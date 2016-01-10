<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
</head>
<body>
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>客户列表</a></li>
			</ul>
		</div>
		<form id="myform" method="post">
		<table class="ordertable">
			<tr class="tabletitle">
				<td>客户编号</td>
				<td>客户姓名</td>
				<td>地址</td>
				<td>电话</td>
				<td>操作</td>
			</tr>
			<?php
				require_once "../class/AutoLoad.php";
				$pagenum=8;		//每页个数
				$page=$_GET['page'];	//当前页数
				$customer=new Customer();
				$countarr=$customer->countCustomer(); 	//查询总个数
				$count=$countarr[0][0];
				$pagecount=ceil($count/$pagenum); 	//总页数
				$start=($page-1)*$pagenum;		//查询开始值
				$res=$customer->listCustomer($start, $pagenum);
				foreach ($res as $row) {
					
						echo '<tr class="tablebody">';
						echo "<td>{$row['id']}</td>";
						echo "<td>{$row['name']}</td>";
						echo "<td>{$row['address']}</td>";
						echo "<td>{$row['phone']}</td>";	
						echo "<td><button class='addorderbutton' onclick='orderRecord({$row['id']})'>订单统计</button></td>";
						echo '</tr>';
				
				}
			?>
		</table>
		</form>
	</div>
	<div class="page">
		
		<?php

			if($page==1){
				if($pagecount==1){
					$pagelast=1;
					$pagenext=$pagecount;
				}else{
					$pagelast=1;
					$pagenext=$page+1;
				}
			}else if($page==$pagecount){
					$pagelast=$page-1;
					$pagenext=$pagecount;
			}else{
					$pagelast=$page-1;
					$pagenext=$page+1;
			}

			echo '<a href="stuffmanage.php?page=1">首页</a>';
			echo '<a href="stuffmanage.php?page='.$pagelast.'">上一页</a>';
			if($page==1){
				if($pagecount==1){
					echo '<a id="focue_a">'.$page.'</a>';
				}else{
					echo '<a id="focue_a">'.$page.'</a>';
					echo '<a href="stuffmanage.php?page='.$pagenext.'">'.$pagenext.'</a>';
				}
			}else if($page==$pagecount){
				echo '<a href="stuffmanage.php?page='.$pagelast.'">'.$pagelast.'</a>';
				echo '<a id="focue_a">'.$page.'</a>';
			}else{
				echo '<a href="stuffmanage.php?page='.$pagelast.'">'.$pagelast.'</a>';
				echo '<a id="focue_a">'.$page.'</a>';
				echo '<a href="stuffmanage.php?page='.$pagenext.'">'.$pagenext.'</a>';
			}

			echo '<a href="stuffmanage.php?page='.$pagenext.'">下一页</a>';
			echo '<a href="stuffmanage.php?page='.$pagecount.'">末页</a>';
		?>
		
	</div>
	<script type="text/javascript">
	function orderRecord(id){
		var form = document.getElementById("myform");
		form.action="customerOrders.php?page=1&cid="+id;
		form.submit();
	}
	</script>
</body>