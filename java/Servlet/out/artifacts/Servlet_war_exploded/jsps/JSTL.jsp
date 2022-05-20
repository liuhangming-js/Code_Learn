<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %><%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/19
  Time: 19:30
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>JSTL:ForEach</title>
</head>
<body>
<%
    List<Integer> a = new ArrayList<>();
    int n = 5;
    while(n != 0) {
        a.add(n);
        n--;
    }
    request.setAttribute("list", a);
%>
<B><c:out value="不指定begin和end的迭代"/></B>
<br>
<c:forEach var="element" items="${list}">
    <c:out value="${element}"/>
    <br>
</c:forEach>

</body>
</html>
