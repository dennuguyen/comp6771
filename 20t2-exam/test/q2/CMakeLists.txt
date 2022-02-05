cxx_test(
   TARGET q2.acc.cols
   FILENAME "acc.cols.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.acc.element
   FILENAME "acc.element.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.acc.rows
   FILENAME "acc.rows.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.copy
   FILENAME "ctor.copy.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.default
   FILENAME "ctor.default.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.dim
   FILENAME "ctor.dim.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.istream
   FILENAME "ctor.istream.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.mn
   FILENAME "ctor.mn.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ctor.move
   FILENAME "ctor.move.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)


cxx_test(
   TARGET q2.friend.add
   FILENAME "friend.add.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.friend.mult
   FILENAME "friend.mult.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.friend.ostream
   FILENAME "friend.ostream.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.friend.istream
   FILENAME "friend.istream.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.friend.sub
   FILENAME "friend.sub.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.friend.transpose
   FILENAME "friend.transpose.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.internal_rep
   FILENAME "internal_rep.cpp"
   LINK range-v3 gsl::gsl-lite-v1
   COMPILER_OPTIONS -Wno-error=keyword-macro
)

cxx_test(
   TARGET q2.iter.models.bidirectional
   FILENAME "iter.models.bidirectional.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.forward
   FILENAME "iter.models.forward.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.incrementable
   FILENAME "iter.models.incrementable.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.indirectly_readable
   FILENAME "iter.models.indirectly_readable.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.input
   FILENAME "iter.models.input.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.random
   FILENAME "iter.models.random.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.models.sentinel_for
   FILENAME "iter.models.sentinel_for.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.iter.models.weakly_incrementable
   FILENAME "iter.models.weakly_incrementable.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.range.bidirectional
   FILENAME "iter.range.bidirectional.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.range.forward
   FILENAME "iter.range.forward.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.range.input
   FILENAME "iter.range.input.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.range.random
   FILENAME "iter.range.random.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.iter.range.reverse
   FILENAME "iter.range.reverse.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.mods.element
   FILENAME "mods.element.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.mods.transpose
   FILENAME "mods.transpose.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.add
   FILENAME "ops.add.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.copy
   FILENAME "ops.copy.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.eq
   FILENAME "ops.eq.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.move
   FILENAME "ops.move.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.mult
   FILENAME "ops.mult.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.ops.sub
   FILENAME "ops.sub.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)

cxx_test(
   TARGET q2.static.identity
   FILENAME "static.identity.cpp"
   LINK range-v3 gsl::gsl-lite-v1
)