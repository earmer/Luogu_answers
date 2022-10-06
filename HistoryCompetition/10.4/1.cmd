:a
.\\t1-gen.exe > t1-test.in
.\\t1.exe < t1-test.in > t1a.out
.\\t1-p.exe < t1p-test.in > t1b.out
fc t1a.out t1b.out
goto a