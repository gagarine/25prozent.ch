<?php
// $Id$
/**
 * @file
 * Contains the basic 'er_definition' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to an
 * entity relationship definition.
 */
class views_handler_field_er_definition extends views_handler_field {

  function init(&$view, $options) {
    parent::init($view, $options);
    if (!empty($this->options['link_to_er_definition'])) {
      $this->additional_fields['did'] = array('table' => 'er_definition', 'field' => 'did');
      if (module_exists('translation')) {
        $this->additional_fields['language'] = array('table' => 'er_definition', 'field' => 'language');
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_er_definition'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_er_definition'] = array(
      '#title' => t('Link this field to its relationship definition editing form'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_er_definition']),
    );
  }

  /**
   * Render whatever the data is as a link to the node.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_er_definition']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/structure/er/" . $values->{$this->aliases['did'] . '/edit'};
      if (isset($this->aliases['language'])) {
        $languages = language_list();
        if (isset($languages[$values->{$this->aliases['language']}])) {
          $this->options['alter']['language'] = $languages[$values->{$this->aliases['language']}];
        }
        else {
          unset($this->options['alter']['language']);
        }
      }
    }
    return $data;
  }

  function render($values) {
    return $this->render_link(check_plain($values->{$this->field_alias}), $values);
  }
}
