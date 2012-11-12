<?php

function theme_course_navigation($vars) {
  $output = '';
  $node = $vars['node'];
  $course_data = $vars['course_data'];
  
  $output .= '<div id="course-navigation-wrapper">';
    
    $output .= '<h3 class="course-title-wrapper">' . $course_data['title'] . '</h3>';
    
    $image_settings = array(
      'style_name' => 'medium_300_300',
      'path' => $course_data['uri'],
      'alt' => $course_data['field_image_alt'],
      'title' => '',
      'attributes' => array('class' => 'image'),
      'getsize' => FALSE,
    );
    $output .= '<div class="course-logo-wrapper">' . theme('image_style', $image_settings) . "</div>";
  
    if ($vars['prev_lesson']) {
      $output .= '<div class="nav-item">';
        $output .= '<div class="title">' . t('Предыдуший урок: ') . '</div>' . l($vars['prev_lesson']['title'], 'node/' . $vars['prev_lesson']['entity_id']);
      $output .= '</div>';
    }
    $output .= '<div class="nav-item">';
      $output .= '<div class="title">' . t('Текущий урок: ') . '</div>' . $node->title;
    $output .= '</div>';
    if ($vars['next_lesson']) {
      $output .= '<div class="nav-item">';
        $output .= '<div class="title">' . t('Следующий урок: ') . '</div>' . l($vars['next_lesson']['title'], 'node/' . $vars['next_lesson']['entity_id']);
      $output .= '</div>';
    }
  $output .= '</div>';
  
  return $output;
}