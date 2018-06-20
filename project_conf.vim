nmap ,lt :Dispatch leetcode test % -t 
nmap <silent> ,ls :Dispatch leetcode submit %<cr>

nmap ,ll :Ecapture leetcode list 

function! s:LeetcodeGetProblem(id, ...)
    let l:lang = 'golang'
    if a:0 > 0
        let l:lang = a:1
    endif

    execute(printf(':Dispatch leetcode show -gx -e tvim -l %s %s', l:lang, a:id))
endfunction

command! -nargs=+ LeetcodeShow call <SID>LeetcodeGetProblem(<f-args>)

nmap ,lg :LeetcodeShow 

function! s:GoRunTest()
    let l:fname = substitute(expand('%'), '_test', '', '')
    let l:out_filename = 'autogen_test_run.go'
    let l:dir = expand('%:p:h')
    silent! call system(printf('gsed "1i \package main" %s > %s/%s', l:fname, l:dir, l:out_filename))
    execute(printf(':Dispatch go test -v %s %s', l:out_filename, expand('%')))
endfunction

autocmd FileType go nmap <buffer> ,rt :call <SID>GoRunTest()<cr>

command! -nargs=0 GoTest call s:GoRunTest()
