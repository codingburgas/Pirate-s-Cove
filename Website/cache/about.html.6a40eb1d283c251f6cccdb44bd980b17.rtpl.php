<?php if(!class_exists('raintpl')){exit;}?><?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("header.html") . ( substr("header.html",-1,1) != "/" ? "/" : "" ) . basename("header.html") );?>
<link rel="stylesheet" type="text/css" href="assets/styles/about-style.css">
 
<div class="container">
<section>
  <h1 class="title">Our team</h1>
  <div class="reveal fade-left">
    <div class="text-container">
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Lubomir Bozukov</h3>
        	<img class="image" alt="Lubomir Bozukov" src="assets/Images/Team Members/bozukov.png">  
		</div>      
        <p>
        	One of our scrum trainers. He mentored the team with Georgi Mateev.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Georgi Mateev</h3>
        	<img class="image" alt="Georgi Mateev" src="assets/Images/Team Members/mateev.png">  
		</div>  
        <p>
          One of our scrum trainers. He mentored the team with Lubomir Bozukov.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Bozhidar Boyadzhiev</h3>
        	<img class="image" alt="Bozhidar Boyadzhiev" src="assets/Images/Team Members/boyadzhiev.jpg">  
		</div>  
        <p>
          One of our backend-developers. He helped with the website and connected the database with the website and the game.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Georgi Zhekov</h3>
        	<img class="image" alt="Georgi Zhekov" src="assets/Images/Team Members/zhekov.jpg">  
		</div>  
        <p>
          One of our backend-developers. He made our game with the help of Georgi Zhekov.
        </p>
      </div>
    </div>
    <div class="text-container">
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Mario Zlatev</h3>
        	<img class="image" alt="Mario Zlatev" src="assets/Images/Team Members/zlatev.jpg">  
		</div>  
        <p>
          One of our backend-developers. He made our game with the help of Mario Zlatev.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Martin Stoyanov</h3>
        	<img class="image" alt="Martin Stoyanov" src="assets/Images/Team Members/stoyanov.png">  
		</div>  
        <p>
          One of our frontend-developers. He created the logo and helped with the design of the website.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Ivan Dochev</h3>
        	<img class="image" alt="Ivan Dochev" src="assets/Images/Team Members/dochev.png">  
		</div>  
        <p>
          One of our frontend-developers. He contributed to creating the website.
        </p>
      </div>
      <div class="text-box">
		<div style="display: flex;">
			<h3 style="flex: 50%">Kaloyan Georgiev</h3>
        	<img class="image" alt="Kaloyan Georgiev" src="assets/Images/Team Members/georgiev.png">  
		</div>  
        <p>
		 One of our frontend-developers. he helped with the about us page.
        </p>
      </div>
    </div>
  </div>
</section>
</div>

<script src="assets/scripts/transition.js"></script>
<?php $tpl = new RainTPL;$tpl_dir_temp = self::$tpl_dir;$tpl->assign( $this->var );$tpl->display( dirname("footer.html") . ( substr("footer.html",-1,1) != "/" ? "/" : "" ) . basename("footer.html") );?>