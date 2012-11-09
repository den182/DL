<?php

function theme_course_navigation($vars) {
  $output = '';
  $node = $vars['node'];
  
  $output .= '<div id="course-navigation-wrapper">';
    if ($vars['prev_lesson']) {
      $output .= '<div>';
        $output .= t('Prev lesson: ') . '<br />' . l($vars['prev_lesson']['title'], 'node/' . $vars['prev_lesson']['entity_id']);
      $output .= '</div>';
    }
    $output .= '<div>';
      $output .= t('Current lesson: ') . '<br />' . $node->title;
    $output .= '</div>';
    if ($vars['next_lesson']) {
      $output .= '<div>';
        $output .= t('Next lesson: ') . '<br />' . l($vars['next_lesson']['title'], 'node/' . $vars['next_lesson']['entity_id']);
      $output .= '</div>';
    }
  $output .= '</div>';
  
  return $output;
}