<?php if(!class_exists('raintpl')){exit;}?><?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>
<link rel="stylesheet" type="text/css" href="assets/styles/registration-style.css">

<div class="container">
      <form action="inc/signup.inc.php" method="post">
        <h1 class="form-title">Sign Up</h1>
         <label for="email">Email</label>
         <br>
         <input type="email" id="email" name="email" placeholder="Your email.." required>
         <br>
         <label for="password">Password</label>
         <br>
         <input type="password" id="password" name="password" placeholder="Your password.." required>
         <br>
         <label for="repassword">Repeat Password</label>
         <br>
         <input type="password" id="repassword" name="repassword" placeholder="Your password.." required>
         <br>

         <?php echo $msg;?>

        <input type="submit" value="Submit" name="submit">
      </form>
</div>

<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>