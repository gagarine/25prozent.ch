<?php

class views_handler_relationship_er_instance extends views_handler_relationship {
  /**
   * Called to implement a relationship in a query.
   */
//  function query() {
//    dsm(func_get_args());
//    // Figure out what base table this relationship brings to the party.
//    $table_data = views_fetch_data($this->definition['base']);
//    $base_field = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];
//
//    $this->ensure_my_table();
//
//    $def = $this->definition;
//    $def['table'] = $this->definition['base'];
//    $def['field'] = $base_field;
//    $def['left_table'] = $this->table_alias;
//    $def['left_field'] = $this->field;
//    if (!empty($this->options['required'])) {
//      $def['type'] = 'INNER';
//    }
//
//    if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
//      $join = new $def['join_handler'];
//    }
//    else {
//      $join = new views_join();
//    }
//
//    $join->definition = $def;
//    $join->construct();
//    $join->adjusted = TRUE;
//
//    // use a short alias for this:
//    $alias = $def['table'] . '_' . $this->table;
//
//    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);
//  }
}