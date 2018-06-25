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

function! s:LeetcodePrepare()
    let l:submit_filename = expand('%') ."_tmp.go"
    execute(':w! ' .l:submit_filename)
    call system('gsed -i "/^package main/d" ' .l:submit_filename)

    return l:submit_filename
endfunction

function! LeetcodeRunTest()
    if &ft == 'go'
        let file = s:LeetcodePrepare()
        execute(printf('Dispatch leetcode test %s -t %s; rm %s', file, LeetcodeGetTestCase(), file))
    else
        execute('Dispatch leetcode test % -t ' .LeetcodeGetTestCase())
    endif
endfunction

nmap ,lt :call LeetcodeRunTest()<cr>

function! LeetcodeSubmit()
    if &ft == "go"
        let file = s:LeetcodePrepare()
        execute(printf(':Dispatch leetcode submit %s ; rm %s', file, file))
    else
        execute(':Dispatch leetcode submit %')
    endif
endfunction

nmap <silent> ,ls :call LeetcodeSubmit()<cr>

nmap ,ll :Etcapture! leetcode list 

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

function! s:GoAddPackageLine()
    if &ft != 'go'
        return
    endif

    if search('^\s*package main', 'wn') > 0
        return
    endif

    call append(0, 'package main')
    update
endfunction

autocmd BufReadPost,BufWritePost *.go call <SID>GoAddPackageLine()

autocmd FileType go nmap <buffer> ,rt :call <SID>GoRunTest()<cr>

command! -nargs=0 GoTest call s:GoRunTest()
