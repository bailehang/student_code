@dir /a>a.txt
@for /f "skip=5 tokens=4" %%i in (a.txt) do attrib -s -h -a -r %%i

@del a.txt
