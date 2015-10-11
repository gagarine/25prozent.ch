<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <ul class="menu nav navbar-nav pull-right">
  <li class="dropdown">
    <a class="dropdown-toggle" data-toggle="dropdown" href="#">
      <?php print t('Choose language'); ?> <span class="caret"></span>
    </a>
    <ul class="dropdown-menu" role="menu">
      <?php print $content ?>
    </ul>
    </li>
  </ul>

</section> <!-- /.block -->
