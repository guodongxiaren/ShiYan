<?php
	function AutoLoad($classname){
		$dir=__DIR__.'/';
		$arr = array('class/','');
		foreach ($arr as $value) {
			if(file_exists($dir.$value.$classname.".php")){
				require_once "{$dir}{$value}{$classname}.php";
				//echo "包含文件成功！";
			}
		}
	}
	spl_autoload_register("AutoLoad");
?>