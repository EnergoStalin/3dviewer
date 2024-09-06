add_requires(
  's21rules'
)

target('s21lib')
  set_kind('static')
  add_files('*.cpp')
  set_group('lib')

  add_includedirs('.', { public = true })
  add_rules(
    '@s21rules/cxxlib'
  )
target_end()
