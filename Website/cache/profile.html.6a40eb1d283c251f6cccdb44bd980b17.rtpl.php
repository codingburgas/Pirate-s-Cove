<?php if(!class_exists('raintpl')){exit;}?><?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>
<link rel="stylesheet" type="text/css" href="assets/styles/profile-style.css">

<div class="container">
    <h1 class="welcome-heading">Hello, adventurer!</h1>
    <?php if( $get["login"] =='success' ){ ?>
        <h3 class="success">You have successfully logged in!</h1>
    <?php } ?>

    <div class="inventory">
        <h1>Your inventory:</h1>
        <div class="items">
            <?php $counter1=-1; if( isset($items) && is_array($items) && sizeof($items) ) foreach( $items as $key1 => $value1 ){ $counter1++; ?>
                <img src="assets/Images/Items/<?php echo $value1["item1"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item2"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item3"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item4"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item5"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item6"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item7"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item8"];?>.png">
                <img src="assets/Images/Items/<?php echo $value1["item9"];?>.png">
            <?php } ?>            
        </div>
    </div>

</div>

<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>