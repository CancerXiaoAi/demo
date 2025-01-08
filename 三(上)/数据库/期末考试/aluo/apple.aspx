<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="apple.aspx.cs" Inherits="luoyq.apple" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style>
         *{margin:0 ;padding:0;}
         
          
</style>
</head>
    
<body>
    <form id="form1" runat="server">
        <div >
            <asp:Table ID="MYTABLE" name="MYTABLE1" runat="server">
                <asp:TableRow>
                    <asp:TableCell>山东红富士</asp:TableCell>
                    <asp:TableCell>13.5/份 500g</asp:TableCell>
                    <asp:TableCell><asp:Button Text="+" ID="apple2"  runat="server" name="mybtn" OnClick="add"/></asp:TableCell>
                    
                   
                </asp:TableRow>
             </asp:Table>
       <asp:Button Text="save"  runat="server" OnClick="save"/>
        </div>

    </form>
</body>
</html>
