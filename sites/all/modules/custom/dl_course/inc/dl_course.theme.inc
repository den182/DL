<?php

function theme_course_navigation($vars) {
  $output = '';
  $node = $vars['node'];
  $course_data = $vars['course_data'];
  
  $output .= '<div id="course-navigation-wrapper">';
    
    $output .= '<h3 class="course-title-wrapper">' . $course_data['title'] . '</h3>';
    
    $image_settings = array(
      'style_name' => 'medium',
      'path' => $course_data['uri'],
      'alt' => $course_data['field_image_alt'],
      'title' => '',
      'attributes' => array('class' => 'image'),
      'getsize' => FALSE,
    );
    $output .= '<div class="course-logo-wrapper">' . theme('image_style', $image_settings) . "</div>";
  
    if ($vars['prev_lesson']) {
      $output .= '<div>';
        $output .= t('Предыдуший урок: ') . '<br />' . l($vars['prev_lesson']['title'], 'node/' . $vars['prev_lesson']['entity_id']);
      $output .= '</div>';
    }
    $output .= '<div>';
      $output .= t('Текущий урок: ') . '<br />' . $node->title;
    $output .= '</div>';
    if ($vars['next_lesson']) {
      $output .= '<div>';
        $output .= t('Следующий урок: ') . '<br />' . l($vars['next_lesson']['title'], 'node/' . $vars['next_lesson']['entity_id']);
      $output .= '</div>';
    }
  $output .= '</div>';
  
  return $output;
}