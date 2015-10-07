<?php
/**
 * @file
 * template.php
 */

/**
* Preprocess variables for node.tpl.php
*
* @see node.tpl.php
*/
function learn_preprocess_node(&$variables) {

// That will let you use a template file like: node--[type|nodeid]--teaser.tpl.php
if($variables['view_mode'] == 'teaser') {
 $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->type . '__teaser';
}

}


