<%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/19
  Time: 14:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>EL获取域中简单数据</title>
</head>
<body>
    <%
        request.setAttribute("rkey", "rvalue");
        session.setAttribute("rkey", "svalue");
        session.setAttribute("skey", "svalue");
        application.setAttribute("akey", "avalue");
    %>
    获取request的数据:
    老方式:<%=request.getAttribute("rkey")%><br>
    el方式:${requestScope.rkey}<br>
    <hr>
    获取session的数据:
    老方式:<%=session.getAttribute("rkey")%><br>
    el方式:${sessionScope.skey}<br>
    <hr>
    获取application的数据:
    老方式:<%=application.getAttribute("akey")%><br>
    el方式:${applicationScope.akey}<br>
    <hr>
    获取application的数据失败:
    老方式:<%=application.getAttribute("aakey")%><br>
    el方式:${applicationScope.aakey}<br>
    <hr style="border-color: red">
    便捷方式：(从小域往大域找，找到后不再继续)
    ${rkey}, ${skey}, ${akey}, ${aakey}
    <hr style="border-color: red">
</body>
</html>
