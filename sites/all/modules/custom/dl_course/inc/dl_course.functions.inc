<?php

/**
 * content for course_navigation block
 */

function _dl_course_get_course_navigation_block_content() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    $order_number = $node->field_order_number['und'][0]['value'];

    $query = db_select('field_data_field_order_number' , 'fon');
    $query->fields('fon', array('entity_id'));
    $query->fields('n', array('title'));
    $query->innerJoin('field_data_field_lessons', 'fl', 'fl.field_lessons_target_id = fon.entity_id');
    $query->innerJoin('node', 'n', 'fon.entity_id = n.nid');
    $query->condition('fon.entity_id', $node->nid, '<>');
    $query->condition('fon.field_order_number_value', $order_number, '>');
    $query->orderBy('fon.field_order_number_value');
    $query->range(0, 1);
    
    $nextLesson = $query->execute()->fetchAssoc();
    
    $query = db_select('field_data_field_order_number' , 'fon');
    $query->fields('fon', array('entity_id'));
    $query->fields('n', array('title'));
    $query->innerJoin('field_data_field_lessons', 'fl', 'fl.field_lessons_target_id = fon.entity_id');
    $query->innerJoin('node', 'n', 'fon.entity_id = n.nid');
    $query->condition('fon.entity_id', $node->nid, '<>');
    $query->condition('fon.field_order_number_value', $order_number, '<');
    $query->orderBy('fon.field_order_number_value', 'DESC');
    $query->range(0, 1);
    
    $prevLesson = $query->execute()->fetchAssoc();
    
    $vars = array();
    $vars['prev_lesson'] = $prevLesson; 
    $vars['next_lesson'] = $nextLesson;
    $vars['node'] = $node; 
        
    return theme('course_navigation', $vars);
  }
  return FALSE;
}