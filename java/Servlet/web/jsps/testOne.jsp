<%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/5
  Time: 14:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>My JSP 'login.jsp' starting page</title>
</head>
<body>
<%
    String req = "request";
    String ses = "session";
    request.setAttribute("reqName", req);
    session.setAttribute("sessionName", ses);
    response.sendRedirect("testTwo.jsp");
%>
</body>
</html>
