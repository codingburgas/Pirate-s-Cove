<?php if(!class_exists('raintpl')){exit;}?>  <?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>
<link rel="stylesheet" type="text/css" href="assets/styles/index-style.css">

<div class="container">

  <?php echo $msg;?>

    <div class="section-one">
      <div class="column">
        <h1>Welcome, adventurers</h1>
        <p>Here you can find more information about our game filled with adventures and riddles. Start your journey on a deserted island, find the pirate treasure and survive!</p>
      </div>
      <div class="column">
        <img class="welcome-image" src="assets/Images/welcome-screen.png" alt="Welcome screen for our game">
      </div>
    </div>
    <div class="section-two">
      <div class="column">
        <a class="download" href="Pirate's Cove.zip" download><i class="fa fa-download"></i> Download</a>  
      </div>
      <div class="column">
        <h1>Let's play, adventurers!</h1>
        <p>Ready to kick off your adventure? Download the game from this button!</p>        
      </div>
    </div>
    <div class="section-three">
      <form action="inc/mail.inc.php" method="post">
        <h1 class="form-title">Get in touch</h1>
        <div style="display: flex;">
          <div style="flex: 50%;">
            <label for="fname">First Name</label>
            <input type="text" id="fname" name="firstname" placeholder="Your name.." required>
          </div>
          <div style="flex: 50%; margin-left: 2%;">
            <label for="lname">Last Name</label>
            <input type="text" id="lname" name="lastname" placeholder="Your last name.." required>
          </div>
        </div>

        <label for="email">Email</label>
        <input type="email" id="email" name="email" placeholder="Your email.." required>

        <label for="subject">Subject</label>
        <textarea id="subject" name="subject" placeholder="Write something.." style="height:100px"></textarea>

        <input type="submit" value="Submit" name="submit">
      </form>
    </div>
  }
</div>

<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>