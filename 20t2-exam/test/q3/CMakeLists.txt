
cxx_test(
   TARGET test_q3_record_deserialisation
   FILENAME "test_q3_record_deserialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_serialisation
   FILENAME "test_q3_record_serialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_get_value
   FILENAME "test_q3_record_get_value.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_set_value
   FILENAME "test_q3_record_set_value.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_has_attribute
   FILENAME "test_q3_record_has_attribute.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_delete_attribute
   FILENAME "test_q3_record_delete_attribute.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_count
   FILENAME "test_q3_record_count.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_escape_deserialisation
   FILENAME "test_q3_record_escape_deserialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_record_escape_serialisation
   FILENAME "test_q3_record_escape_serialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_serialisation
   FILENAME "test_q3_database_serialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_deserialisation
   FILENAME "test_q3_database_deserialisation.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_insert
   FILENAME "test_q3_database_insert.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_count
   FILENAME "test_q3_database_count.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_delete_matching
   FILENAME "test_q3_database_delete_matching.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_database_select
   FILENAME "test_q3_database_select.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_equals
   FILENAME "test_q3_query_equals.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_less_than
   FILENAME "test_q3_query_less_than.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_greater_than
   FILENAME "test_q3_query_greater_than.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_starts_with
   FILENAME "test_q3_query_starts_with.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_and
   FILENAME "test_q3_query_and.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_or
   FILENAME "test_q3_query_or.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET test_q3_query_not
   FILENAME "test_q3_query_not.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)
