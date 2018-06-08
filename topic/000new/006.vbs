' *============================================================================*
' * 批量编码转换包括GB2312，UTF-8，Unicode，支持拖动，可扩展到右菜单（发送到） *
' * CodeChange.vbs     BY: yongfa365 http://www.yongfa365.com       2007-10-04 *
' * ANSI2UTF8.vbs      BY: fastslz   http://bbs.cn-dos.net          2007-12-03 *
' *============================================================================*
aCode = "GB2312"
bCode = "UTF-8"
Set objArgs = WScript.Arguments
If objArgs.Count=0 Then
    MsgBox "本脚本仅支持"&aCode&"到"&bCode&"的转换，请将您要转换的文件拖到这个文件上！    "&vbCrLf&"命令行用法：ANSI2UTF8.vbs [驱动器][目录][文件名1][文件名2]...", vbInformation, "拖拽批量编码转换工具 BY: fastslz"
End If
    For I = 0 To objArgs.Count - 1
        FileUrl = objArgs(I)
        Call CheckCode (FileUrl)
        Call WriteToFile(FileUrl, ReadFile(FileUrl, aCode), bCode)
    Next
Function ReadFile(FileUrl, CharSet)
    Dim Str
    Set stm = CreateObject("Adodb.Stream")
    stm.Type = 2
    stm.mode = 3
    stm.charset = CharSet
    stm.Open
    stm.loadfromfile FileUrl
    Str = stm.readtext
    stm.Close
    Set stm = Nothing
    ReadFile = Str
End Function

Function WriteToFile (FileUrl, Str, CharSet)
    Set stm = CreateObject("Adodb.Stream")
    stm.Type = 2
    stm.mode = 3
    stm.charset = CharSet
    stm.Open
    stm.WriteText Str
    stm.SaveToFile FileUrl, 2
    stm.flush
    stm.Close
    Set stm = Nothing
End Function

Function CheckCode (FileUrl)
    Dim slz
    set slz = CreateObject("Adodb.Stream") 
    slz.Type = 1
    slz.Mode = 3
    slz.Open
    slz.Position = 0
    slz.Loadfromfile FileUrl
    Bin=slz.read(2)
    if AscB(MidB(Bin,1,1))=&HEF and AscB(MidB(Bin,2,1))=&HBB Then
       Codes="UTF-8"
       elseif AscB(MidB(Bin,1,1))=&HFF and AscB(MidB(Bin,2,1))=&HFE Then
              Codes="Unicode"
              else
              Codes="GB2312"
    end if
    if not aCode = Codes Then
           MsgBox "待处理文件 “"&FileUrl&"”"&vbCrLf&"该文件原始编码不是"&aCode&"，本脚本仅支持"&aCode&"到"&bCode&"的转换！    ",vbInformation,"错误终止"
           WScript.Quit
    end if
    slz.Close
    set slz = Nothing
End Function