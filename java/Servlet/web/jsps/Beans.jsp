<%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/19
  Time: 14:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="test.Beans.Student" %>
<html>
<head>
    <title>Java Beans</title>
</head>
<body>
<jsp:useBean id="student" class="test.Beans.Student" scope="application"/>
<%
    Student alice = new Student("alice", "alice@niit.com", "woman");
    pageContext.setAttribute("student", alice);
%>
<h2>使用EL表达式访问JavaBean</h2>
<h3>姓名:${student.sname}</h3>
<h3>邮箱:${student.email}</h3>
<h3>性别:${student.sex}</h3>
</body>
</html>
