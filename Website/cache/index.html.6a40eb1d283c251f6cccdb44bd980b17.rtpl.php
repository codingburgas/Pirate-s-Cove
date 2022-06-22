<?php if(!class_exists('raintpl')){exit;}?><?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>

<div class="home">
	<div class="welcome-section">
	
	</div>
	<div class="download-section">
		
	</div>
	<div class="contact-section">
		
	</div>
</div>

<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>