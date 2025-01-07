<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="WebApplication3.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style>
        td{
            border: 1px solid #000;
        }
    </style>
</head>
<body>
    <form runat="server">
        <asp:Table runat="server">
            <asp:TableRow>
                <asp:TableCell>香蕉</asp:TableCell>
                <asp:TableCell>10元</asp:TableCell>
                <asp:TableCell><asp:Button id="banana" Text="+" runat="server" OnClick="add"/></asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>苹果</asp:TableCell>
                <asp:TableCell>5元</asp:TableCell>
                <asp:TableCell><asp:Button id="apple" Text="+" runat="server" OnClick="add"/></asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>梨</asp:TableCell>
                <asp:TableCell>5元</asp:TableCell>
                <asp:TableCell><asp:Button id="pair" Text="+" runat="server" OnClick="add"/></asp:TableCell>
            </asp:TableRow>
        </asp:Table>
        <asp:Button runat="server" OnClick="submit" Text="结算"/>
        <asp:Button runat="server" OnClick="clean" Text="清零"/>
    </form>
</body>
</html>
