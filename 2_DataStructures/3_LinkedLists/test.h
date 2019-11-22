#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

#ifndef TEST_H
#define TEST_H

void test_new_linked_list();

void test_linked_list_push_front();
void test_linked_list_push_front_multiple();
void test_linked_list_push_front_many();
void test_linked_list_push_front_duplicates();

void test_linked_list_pop_front_empty();
void test_linked_list_pop_front();
void test_linked_list_pop_front_multiple();
void test_linked_list_pop_front_many();
void test_linked_list_pop_front_duplicates();

void test_linked_list_push_back();
void test_linked_list_push_back_multiple();
void test_linked_list_push_back_many();
void test_linked_list_push_back_duplicates();

void test_linked_list_pop_back_empty();
void test_linked_list_pop_back();
void test_linked_list_pop_back_multiple();
void test_linked_list_pop_back_many();
void test_linked_list_pop_back_duplicates();

void test_linked_list_push_back_pop_front();
void test_linked_list_push_back_pop_front_multiple();
void test_linked_list_push_back_pop_front_many();

void test_linked_list_push_front_pop_back();
void test_linked_list_push_front_pop_back_multiple();
void test_linked_list_push_front_pop_back_many();

#endif
