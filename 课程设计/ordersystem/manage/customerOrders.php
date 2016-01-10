<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
	<?php
		require_once "../class/AutoLoad.php";
		$pagenum=8;		//每页个数
		$page=$_GET['page'];	//当前页数
		$cid =$_GET['cid'];
		$order=new Order();
		$totalPrice=$order->getTotalPriceByCid($cid);
	?>
</head>
<body class="ordermanage">
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>客户订单统计</a></li>
			</ul>
		</div>
		<input class="addorderbutton" value="总金额￥" /><?=$totalPrice[0][0]?>
		<table class="ordertable">
			<tr class="tabletitle">
					<td>订单编号</td>
					<td>客户名称</td>
					<td>产品名称</td>
					<td>订购单价</td>
					<td>订购数量</td>
					<td>订购金额</td>
					<td>订购日期</td>
					<td>交货日期</td>
			</tr>
			<?php
				$countarr=$order->countOrderByCid($cid); 	//查询总个数

				//var_dump($countarr);
				$count=$countarr[0][0];
				//echo $count;
				$pagecount=ceil($count/$pagenum); 	//总页数
				$start=($page-1)*$pagenum;		//查询开始值
				$res=$order->listOrderByCid($start,$pagenum,$cid);
				foreach ($res as $row) {
					echo '<tr class="tablebody">';
					echo "<td>{$row[0]}</td>";
					echo "<td>{$row[1]}</td>";
					echo "<td>{$row[2]}</td>";
					echo "<td>{$row[3]}</td>";
					echo "<td>{$row[4]}</td>";
					echo "<td>{$row[5]}</td>";
					echo "<td>{$row[6]}</td>";
					echo "<td>{$row[7]}</td>";
					echo '</tr>';
				}
			?>
		</table>
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

			echo '<a href="ordermanage.php?page=1">首页</a>';
			echo '<a href="ordermanage.php?page='.$pagelast.'">上一页</a>';
			if($page==1){
				if($pagecount==1){
					echo '<a id="focue_a">'.$page.'</a>';
				}else{
					echo '<a id="focue_a">'.$page.'</a>';
					echo '<a href="ordermanage.php?page='.$pagenext.'">'.$pagenext.'</a>';
				}
			}else if($page==$pagecount){
				echo '<a href="ordermanage.php?page='.$pagelast.'">'.$pagelast.'</a>';
				echo '<a id="focue_a">'.$page.'</a>';
			}else{
				echo '<a href="ordermanage.php?page='.$pagelast.'">'.$pagelast.'</a>';
				echo '<a id="focue_a">'.$page.'</a>';
				echo '<a href="ordermanage.php?page='.$pagenext.'">'.$pagenext.'</a>';
			}

			echo '<a href="ordermanage.php?page='.$pagenext.'">下一页</a>';
			echo '<a href="ordermanage.php?page='.$pagecount.'">末页</a>';
		?>
		
	</div>
</body>