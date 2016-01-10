<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
	
</head>
<body>
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>添加产品</a></li>
			</ul>
		</div>
		<form action="productAction.php?op=add" method="post">
			<table class="ordertable">
				<tr class="tabletitle"><td>产品名称</td><td>产品简介</td><td>产品单价</td><td>操作</td></tr>
				<tr>
					<td><input name="name" class="addorder" type="text"></td>
					<td><input name="detail" class="addorder" type="text"></td>
					<td><input name="price" class="addorder" type="text"></td>
					<td><input class="addorderbutton" type="submit" value="添加产品"></td>
				</tr>
			</table>
		</form>
</body>