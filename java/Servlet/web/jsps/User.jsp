<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: liuhangming
  Date: 2022/5/19
  Time: 20:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>JSTL_User测试</title>
</head>
<body>
<jsp:useBean id="person" class="test.JSPTags.User"/>
<c:set value="张三" var="name1" scope="session"/>
<c:set var="name2" scope="session">李四</c:set>
<c:set value="赵武" target="${person}" property="name"/>
<c:set target="${person}" property="id">19</c:set>
<li>从session中得到的值:${name1}</li>
<li></li>
</body>
</html>
