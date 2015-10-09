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
function prozent_preprocess_node(&$variables) {


}


function prozent_links__locale_block(&$vars) {

    $vars['attributes']['class'][] = 'nav';
    $content = theme_links($vars);
    return $content;
}