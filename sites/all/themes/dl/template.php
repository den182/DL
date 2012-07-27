<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 
/**
* comment form alter
* 
*/
 
function dl_form_comment_form_alter(&$form, &$form_state, &$form_id) {
  $form['comment_body']['#after_build'][] = 'dl_customize_comment_form';
  unset($form['actions']['preview']);
}

function dl_form_comment_node_article_form_alter (&$form, &$form_state, &$form_id) {
  $form['#prefix'] = '<div class="comment-form-title-wrapper">';
  $form['#suffix'] = '</div>';
}

/**
* Customize comment form
*/
 
function dl_customize_comment_form(&$form) {  
  $form[LANGUAGE_NONE][0]['format']['#access'] = FALSE; // Note LANGUAGE_NONE, you may need to set your comment form language code instead 
  return $form;  
}

/**
* comment preprocess
*/

function dl_preprocess_comment(&$vars) {
  $vars['attributes_array']['class'][] = $vars['zebra']; //Add zebra to classes
}
