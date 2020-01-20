#ifndef TEST_H
#define TEST_H

// new_linked_list
void test_new_linked_list();

// push_front
void test_linked_list_push_front();
void test_linked_list_push_front_multiple();
void test_linked_list_push_front_many();
void test_linked_list_push_front_duplicates();

// pop_front
void test_linked_list_pop_front_empty();
void test_linked_list_pop_front();
void test_linked_list_pop_front_multiple();
void test_linked_list_pop_front_many();
void test_linked_list_pop_front_duplicates();

// push_back
void test_linked_list_push_back();
void test_linked_list_push_back_multiple();
void test_linked_list_push_back_many();
void test_linked_list_push_back_duplicates();

// pop_back
void test_linked_list_pop_back_empty();
void test_linked_list_pop_back();
void test_linked_list_pop_back_multiple();
void test_linked_list_pop_back_many();
void test_linked_list_pop_back_duplicates();

// push_back, pop_front
void test_linked_list_push_back_pop_front();
void test_linked_list_push_back_pop_front_multiple();
void test_linked_list_push_back_pop_front_many();

// push_front, pop_back
void test_linked_list_push_front_pop_back();
void test_linked_list_push_front_pop_back_multiple();
void test_linked_list_push_front_pop_back_many();

// push_front, remove
void test_linked_list_push_front_remove();
void test_linked_list_push_front_remove_multiple();
void test_linked_list_push_front_remove_many();
void test_linked_list_push_front_remove_non_existent();
void test_linked_list_push_front_remove_duplicates();
void test_linked_list_push_front_remove_pop_front();
void test_linked_list_push_front_remove_pop_back();

// push_back, remove
void test_linked_list_push_back_remove();
void test_linked_list_push_back_remove_multiple();
void test_linked_list_push_back_remove_many();
void test_linked_list_push_back_remove_non_existent();
void test_linked_list_push_back_remove_duplicates();
void test_linked_list_push_back_remove_pop_back();
void test_linked_list_push_back_remove_pop_front();

#endif
