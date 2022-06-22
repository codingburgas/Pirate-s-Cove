<?php if(!class_exists('raintpl')){exit;}?><?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>

<div class="home">
    <div class="section-one">
      <div class="column">
        <h1>Welcome, adventurers</h1>
        <p>Here you can find more information about our game filled with adventures and riddles. Start your journey on a deserted island, find the pirate treasure and survive!</p>
      </div>
      <div class="column">
        <img src="" alt="Image here...">
      </div>
    </div>
    <div class="section-two">
      <h1></h1>
      <p></p>
      <a href=""></a>
    </div>
    <div class="section-three">
      <form>
        
      </form>
    </div>
</div>

<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>