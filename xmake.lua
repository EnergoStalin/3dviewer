set_project('3DViewer')
set_version('2')

add_repositories("energostalin https://github.com/EnergoStalin/xmake-repo")
-- add_repositories('local /home/alexv/Source/xmake-repo')

includes(
  '**/xmake.lua'
)

add_requires('gtest')

target('tests')
  add_files('tests.cpp')

  add_rules(
    '@s21rules/cxxtest',
    '@s21rules/libreport'
  )

  on_config(function (target)
    target:set('rundir', path.join(os.projectdir(), 'objects'))
  end)

  add_deps('s21lib')

  set_group('test')
target_end()
