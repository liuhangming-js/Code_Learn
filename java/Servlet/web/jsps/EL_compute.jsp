<%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/19
  Time: 15:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>EL运算</title>
</head>
<body>
<%
  request.setAttribute("a", 11);
  request.setAttribute("b", 22);
  request.setAttribute("c", "33");
  request.setAttribute("d", "kkk");
%>
数字+数字:${a + b}<br>
数字+数字字符串:${a + c}<br>
数字字符串+数字字符串:${c + c}<br>
<%--
报错：
数字+字母字符串
数字字符串+字母字符串
字母字符串+字母字符串
--%>
</body>
</html>
