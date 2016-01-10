<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
</head>
<body>
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>删除客户</a></li>
			</ul>
		</div>
		<table class="ordertable">
			<tr class="tabletitle">
				<td>是否删除</td>
				<td>客户编号</td>
				<td>客户姓名</td>
				<td>地址</td>
				<td>电话</td>
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
				echo "<form action='customerAction.php?op=delete' method='post'>";
				foreach ($res as $row){
						echo '<tr class="tablebody">';
						echo "<td><input type='checkbox' name='id[]' value='{$row[0]}' /></td>";
						echo "<td>{$row[0]}</td>";
						echo "<td>{$row[1]}</td>";
						echo "<td>{$row[2]}</td>";
						echo "<td>{$row[3]}</td>";
						echo "</tr>";
				}
				echo "<tr>";
				echo "<td><input type='submit' class='addorderbutton' value='删除'/></td>";
				echo '</tr>';
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
</body>