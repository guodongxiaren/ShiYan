<head>
	<link rel="stylesheet" type="text/css" href="../css/Style.css">
</head>
<body>
	<div class="manage_body">
		<div class="manage_top">
			<ul>
				<li><a>修改订单</a></li>
			</ul>
		</div>
		<?php
			require_once "../class/AutoLoad.php";
			$id=$_GET['id'];
			$customer = new Customer();	
			$product  = new Product();
			$order    = new Order();
			$cus_res  = $customer->getCustomerNameID();
			$pro_res  = $product->getProductNameID();
			$price = $product->getProductPriceID();
			
			$order->id=$id;
			$detail=$order->getDetail();
			//var_dump($detail);
			echo '<form action="orderAction.php?op=update&id='.$id.'" method="post">';
		?>
			<table class="ordertable">
				<tr class="tabletitle">
					<td>客户名称</td>
					<td>产品名称</td>
					<td>订购单价</td>
					<td>订购数量</td>
					<td>订购金额</td>
					<td>订购日期</td>
					<td>交货日期</td>
					<td>操作</td>
					<td>操作</td>
				</tr>
				<tr>
					<td>
					<?php
						echo '<select name="cid">';
						echo "<option />";
						foreach ($cus_res as $row){
							if ($row[1] == $detail[0]['cid']){
								echo "<option value={$row[1]} selected='selected'>{$row[0]}</option>";
							}
							else{
								echo "<option value={$row[1]}>{$row[0]}</option>";
							}
							
						}
						echo '<select>';
					?>
					</td>
					<td>
					<?php
						echo '<select name="pid" onchange="setPrice(this.options[this.options.selectedIndex].value)">';
						echo "<option />";
						foreach ($pro_res as $row){
							if ($row[1] == $detail[0]['pid']){
								echo "<option value={$row[1]} selected='selected'>{$row[0]}</option>";
							}
							else{
								echo "<option value={$row[1]}>{$row[0]}</option>";
							}
						}
						echo '<select>';
					?>
					
					</td>
					<td><input id="price" class="disabledinput" type="text" disabled="true" value=<?=$detail[0]['price']?> ></td>
					<td>
						<button type="button" onclick="sub1()">-</button>
						<input name="amount" id="amount"  class="addorder" type="text" value=<?=$detail[0]['amount']?> >
						<button type="button" onclick="add1()">+</button>
					</td>
					<td><input id="totalprice" class="disabledinput" type="text" disabled="true" value=<?=$detail[0]['totalprice']?> ></td>
					<td><input name="order_time" class="addorder" type="text" value=<?=$detail[0]['order_time']?> ></td>
					<td><input name="delivery_time" class="addorder" type="text" value=<?=$detail[0]['delivery_time']?> ></td>
					<td><input class="addorderbutton" type="submit" value="确认修改"></td>
					<td><input id="addorderbutton1" class="addorderbutton" type="reset" value="取消修改"></td>
				</tr>
			</table>
		</form>
		<a class="returnbutton" href="orderListupdate.php?page=1">返回</a>
	<script type="text/javascript">
	var price = <?=$price?>;
	function setPrice(index){
		document.getElementById("price").value=price[index];
		document.getElementById("amount").value=0;
		document.getElementById("totalprice").value=0;
	}
	function add1(){
		var amount = document.getElementById("amount");
		var totalprice  = document.getElementById("totalprice");

		var value  = parseInt(amount.value);
		amount.value = value + 1;
		var price  = parseInt(document.getElementById("price").value);
		totalprice.value = price*(value+1);
	}
	function sub1(){
		var amount = document.getElementById("amount");
		var totalprice  = document.getElementById("totalprice");

		var value  = parseInt(amount.value);
		if (value == 0)
			return;
		amount.value = value - 1;
		var price  = parseInt(document.getElementById("price").value);
		totalprice.value = price*(value-1);
	}
	</script>
</body>
