<?php

function theme_course_navigation($vars) {
  $output = '';
  
  $output .= '<div id="course-navigation-wrapper">';
    if ($vars['prev_lesson']) {
      $output .= t('Prev lesson: ') . l($vars['prev_lesson']['title'], 'node/' . $vars['prev_lesson']['entity_id']);
    }
    if ($vars['next_lesson']) {
      $output .= t('Next lesson: ') . l($vars['next_lesson']['title'], 'node/' . $vars['next_lesson']['entity_id']);
    }
  $output .= '</div>';
  
  return $output;
}