/*
 * Copyright (C) 2014 Piotr Esden-Tempski
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <stdlib.h>
#include <check.h>
#include "pprz_algebra.h"

START_TEST(test_first)
{
  ck_assert_int_eq(5, 5);
}
END_TEST

START_TEST(test_second)
{
  ck_assert_str_eq("bla", "blu");
}
END_TEST

Suite * pprz_math_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("Algebra");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_first);
  tcase_add_test(tc_core, test_second);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = pprz_math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
