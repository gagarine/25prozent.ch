<?php // $Id$
/**
 * @file
 *
 * Theme functions for the Entity Relationships module.
 */

/**
 * Theme function for a single Entity Relationship Instance.
 */
function theme_er_instance($variables) {

  $er_instance = $variables['instance'];
  $direction = isset($variables['direction']) ? $variables['direction'] : ER_FROM;
//dsm($er_instance);
  switch ($direction) {
    case ER_FROM:
      $from = $er_instance->entity_from_label;
      $label = $er_instance->party_from_label;
      $to = l($er_instance->entity_to_label, $er_instance->entity_to_uri['path']);
      $output = sprintf('%s %s %s', $from, $label, $to);
      break;
    case ER_TO:
      $from = $er_instance->entity_to_label;
      $label = $er_instance->party_to_label;
      $to = l($er_instance->entity_from_label, $er_instance->entity_from_uri['path']);
      $output = sprintf('%s %s %s', $from, $label, $to);
  }
  return '<div class="er-instance">' . $output . '</div>';
}

/**
 * Theme function for multiple Entity Relationship instances.
 */
function theme_er_instances($variables) {

  $def_instances = $variables['instances'];
  $direction = isset($variables['direction']) ? $variables['direction'] : ER_FROM;
  $direction_class = $direction == ER_FROM ? 'er-from' : 'er-to';
  $output = '<div class="er-instances ' . $direction_class . '">';
  foreach ($def_instances as $did => $instances) {
    foreach ($instances as $instance) {
      $output .= theme('er_instance', array('instance' => $instance, 'direction' => $direction));
    }
  }
  $output .= '</div>';
  return $output;
}