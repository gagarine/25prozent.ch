<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php foreach ($rows as $id => $row): ?>
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
        <?php print $row; ?>
    </div>
<?php endforeach; ?>

<?php // we use this for the button... hacky trick ?>
<?php if (!empty($title)): ?>
    <?php print $title; ?>
<?php endif; ?>
<hr >