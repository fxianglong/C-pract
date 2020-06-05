<%@ page language="java" contentType="text/html;charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>处理表单信息页面</title>

<body>
	<form id="form1" name="form1" method="post" action="MessageServlet">
	留&nbsp;言&nbsp;人：
	<input name="person" type="text" id="person"/><br/><br/>
	留言内容：
	<textarea name="content" cols="30" rows="5" id="content"></textarea><br/><br/>
	<input type="submit" name="Submit" value="提交"/>&nbsp;
	<input type="reset" name="Submit2" value="重置"/>
	</form>
</body>
</html>