<?php

/**
 * @file
 *
 * Provides ER formatter-relatated functions
 */

/**
 * Implements hook_er_formatter_info().
 */
function er_er_formatter_info() {
  return array(
    'simple_list' => array(
      'title'    => t('Simple List'),
      'callback' => 'er_simple_formatter',
    ),
  );
}


/**
 * Return a key/value array of available formatters, suitable for use in
 * a FAPI select element.
 */
function er_formatter_options() {
  $options = array();
  $formatters = module_invoke_all('er_formatter_info');
  if (count(array_keys($formatters)) > 1) {
    // If there's more than one formatter available, add an empty '--Select--'
    // item at the top of the list
    $options[''] = t('--Select--');
  }

  foreach ($formatters as $formatter => $info) {
    $options[$formatter] = $info['title'];
  }
  return $options;
}

/**
 * Formatter for a list of entity relationship occurrences. Returns an unordered
 * list if elements on the opposite side of the relationship, using the plural
 * name of that side of the relationship; for example, when viewing an entity
 * whose role in the relationship is 'Parent', the simple formatter will return
 * a list titled 'Children' containing a list of related entities in the 'Child'
 * role of the relationship.  Returns a renderable array.
 */
function er_simple_formatter($instances, $def, $direction = ER_FROM) {
  $items = array();
  $classes = array('er-instance');
  switch ($direction) {
    case ER_FROM:
      $class = 'er-from';
      $role = er_role_load($def->party_to_rid);
      $id = 'party_to_id';
      $label = 'entity_to_label';
      $path = 'entity_to_uri';
      break;

    case ER_TO:
      $class = 'er-to';
      $role = er_role_load($def->party_from_rid);
      $id = 'party_from_id';
      $label = 'entity_from_label';
      $path = 'entity_from_uri';
      break;
  }
  foreach ($instances as $instance) {
    $item_label = $instance->{$label};
    $item_path = $instance->{$path}['path'];
    $items[] = l($item_label, $item_path, array('attributes' => array('class' => $class . ' er-link')));
  }
  return array(
    '#type' => 'item_list',
    '#title' => $role->name_plural,
    '#items' => $items,
    '#theme' => 'item_list',
    '#attributes' => array('class' => $class . ' er-instances'),
  );
}