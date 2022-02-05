BENCHMARK_F(BenchmarkFixture, ExistingPriceLevel)
(benchmark::State& state) {
    unsigned long idx = 0;

    for (auto _ : state) {
        std::string const& price = std::get<0>(LEVELS[idx]);
        idx = (idx + 1) % LEVELS.size();
        benchmark::DoNotOptimize(book->get_volume(price));
    }
}