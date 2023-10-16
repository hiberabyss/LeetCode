" indent setting
set shiftwidth=2
set tabstop=2
set wrap
set signcolumn=auto

let s:project_root = expand('<sfile>:p:h')

function! GetProblemID()
  return split(expand('%:t'), '\.')[0]
endfunction

function! ShowSolution()
  execute(printf('Ecapture leetcode show -l cpp %s --solution 2> /dev/zero', GetProblemID()))
endfunction

function! LeetcodeCaptureMap()
  nmap <buffer> <silent> o :call LeetcodeOpenProblem()<cr>
  nmap <buffer> <silent> <cr> :call LeetcodeOpenProblem()<cr>
endfunction
autocmd FileType capture call LeetcodeCaptureMap()

command! -nargs=0 GoTest call s:GoRunTest()

function! LeetcodeInit()
  let g:leetcode_lang = fnamemodify($PWD, ':t')
endfunction
call LeetcodeInit()

function! LeetcodeGetTestCase()
    let linenr = search(' Testcase Example: ', 'wn')
    if linenr > 0
        let match_res = matchlist(getline(linenr), '\vTestcase Example: (.*)')
        if len(match_res) > 1
            return match_res[1]
        endif
    endif

    return
endfunction

function! DbgSetup() abort
  " do nothing for test file
  if expand('%:t:r') =~ '_test'
    return
  endif

  " switch to test file when DbgRun
  execute "AT"
endfunction

function! GetQuickfixTestCase()
    " could change to use getqflist()
    copen
    let linenr = search(' testcase: ', 'wn')
    if linenr > 0
        let match_res = matchlist(getline(linenr), '\v testcase: (.*)$')
        if len(match_res) > 1
            return match_res[1]
        endif
    endif
    wincmd w

    return ""
endfunction

function! LeetcodeOpenUrl()
  let linenr = search(' https:\/\/leetcode', 'wn')
  if linenr > 0
    let match_res = matchlist(getline(linenr), '\v (http\S+)')
    if len(match_res) > 1
      let url = substitute(match_res[1], 'description', 'solution', '')
      execute(printf('silent! call system("open %s")', url))
    endif
  endif
endfunction

function! s:LeetcodePrepare()
  let l:submit_filename = expand('%') ."_tmp.go"
  execute(':w! ' .l:submit_filename)
  call system('gsed -i "/^package main/d" ' .l:submit_filename)

  return l:submit_filename
endfunction

function! ClearIncludeFile() abort
  if &ft == "cpp"
    silent g/^#include/d | update
  endif
endfunction

function! LeetcodeRunTest()
  call ClearIncludeFile()
  let qf_test_case = GetQuickfixTestCase()
  if &ft == 'go'
    let file = s:LeetcodePrepare()
    execute(printf('Dispatch leetcode test %s -t %s; rm %s', file, LeetcodeGetTestCase(), file))
  elseif len(qf_test_case) > 0
    execute('Dispatch leetcode test % -t ' .qf_test_case)
  else
    execute('Dispatch leetcode test %')
  endif
endfunction

function! LeetcodeSubmit()
  call ClearIncludeFile()
  if &ft == "go"
    let file = s:LeetcodePrepare()
    execute(printf(':Dispatch leetcode submit %s ; rm %s', file, file))
  else
    execute(':Dispatch leetcode submit %')
  endif
endfunction

function! s:LeetcodeGetProblem(id, ...)
  let l:lang = 'cpp'
  if a:0 > 0
    let l:lang = a:1
  endif

  execute(printf(':Dispatch! leetcode show -gkx -e tvim -l %s %s', l:lang, a:id))
endfunction

function! s:GoRunTest()
  let l:fname = substitute(expand('%'), '_test', '', '')
  execute(printf(':Dispatch go test -v %s %s', l:fname, expand('%')))
endfunction

function! s:GoAddPackageLine()
  if &ft != 'go'
    return
  endif

  if search('^\s*package ', 'wn') > 0
    return
  endif

  call append(0, 'package main')
  update
endfunction

function! LeetcodeOpenProblem()
  let items = matchlist(getline('.'), '\v\[\s*(\d+)\s*\]')
  if len(items) <= 0
    return
  endif

  let problem_id = items[1]
  call s:LeetcodeGetProblem(problem_id, g:leetcode_lang)
endfunction

function! LeetcodeRunCusTest(test)
  execute(printf(':Dispatch leetcode test %s -t %s', expand('%'), a:test))
endfunction
command! -nargs=1 LeetTest call LeetcodeRunCusTest(<q-args>)

nmap <silent> ,lo :call LeetcodeOpenUrl()<cr>
nmap ,lt :call LeetcodeRunTest()<cr>
nmap <silent> ,ls :call LeetcodeSubmit()<cr>
nmap ,la :Evcapture! tac <(leetcode list -t algorithms -q L)<cr>
nmap ,ll :Evcapture! tac <(leetcode list -t algorithms -q eLD)<cr>
nmap ,lm :Evcapture! tac <(leetcode list -t algorithms -q mLD)<cr>
nmap ,le :Evcapture! tac <(leetcode list -t algorithms -q eLD)<cr>
nmap ,lh :Evcapture! tac <(leetcode list -t algorithms -q hLD)<cr>
nmap ,lg :LeetcodeShow 
nmap <A-i> /^\s*$<cr><c-l>cc

function! RunCppTest() abort
  let test_file = printf("%s_test.%s", expand("%:p:r"), expand("%:e"))
  exec "Dispatch crunner run " . test_file
endfunction

autocmd FileType cpp nmap <buffer> <silent> ,rt <CMD>call RunCppTest()<CR>

" autocmd FileType go nmap <buffer> ,rt :call <SID>GoRunTest()<cr>

autocmd BufReadPost,BufWritePost *.go call <SID>GoAddPackageLine()
command! -nargs=0 LeetSolution call ShowSolution()
command! -nargs=+ LeetcodeShow call <SID>LeetcodeGetProblem(<f-args>)

" Linter {{{
let $CPATH = printf("%s/include:", s:project_root) . expand("$CPATH")
let s:include_file = printf('-include %s/include/%s',
      \ expand('<sfile>:p:h'), 'leetcode.h')

let g:ale_cpp_cc_options = '-std=c++20 -Wall ' .s:include_file
let g:ale_cpp_clangtidy_options = s:include_file
ALEDisable | ALEEnable
" }}}

nmap <silent> ,= :sno#[#{#g<cr>:sno#]#}#g<cr>
vmap <silent> ,= :sno#[#{#g<cr>:'<,'>sno#]#}#g<cr>

function! InitLeetcodeCppTestFile() abort
  if wordcount().bytes > 0
    return
  endif

  call snip#do_expand('inclc')
endfunction

augroup LeectCode
  autocmd!
  autocmd BufNewFile *_test.cpp,*_test.cc call InitLeetcodeCppTestFile()
augroup END

" command! -nargs=1 LCget call LeetcodeGet(<q-args>)

" vim:sw=2:ts=2:
