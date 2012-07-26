<article<?php print $attributes; ?>>
  <header>
    <?php if (isset($unpublished)): ?>
      <em class="unpublished"><?php print $unpublished; ?></em>
    <?php endif; ?>
  </header>

  <?php print $picture; ?>

  <footer class="comment-submitted">
   <?php
      print t('!username - !datetime',
      array('!username' => $author, '!datetime' => '<time datetime="' . $datetime . '">' . date('Y/m/d H:i:s', strtotime($datetime)) . '</time>'));
    ?>
  </footer>
  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php if ($signature): ?>
    <div class="user-signature"><?php print $signature ?></div>
  <?php endif; ?>

  <?php if (!empty($content['links'])): ?>
    <nav class="links comment-links clearfix"><?php print render($content['links']); ?></nav>
  <?php endif; ?>

</article>
