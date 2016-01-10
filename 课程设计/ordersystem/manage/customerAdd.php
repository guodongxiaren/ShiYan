<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
	
</head>
<body>
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>添加客户</a></li>
			</ul>
		</div>
		<form action="customerAction.php?op=add" method="post">
			<table class="ordertable">
				<tr class="tabletitle"><td>姓名</td><td>地址</td><td>电话</td><td>操作</td></tr>
				<tr>
					<td><input name="name" class="addorder" type="text"></td>
					<td><input name="address" class="addorder" type="text"></td>
					<td><input name="phone" class="addorder" type="text"></td>
					<td><input class="addorderbutton" type="submit" value="添加客户"></td>
				</tr>
			</table>
		</form>
</body>