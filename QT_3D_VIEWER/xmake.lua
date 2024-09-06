add_requires(
  's21rules',
  'qtgifimage',
  'opengl'
)

target('3DViewer')
  set_kind('binary')
  set_languages('cxx17') -- Somehow it's not inheriting standart from cxx rule when compiling with qt

  add_files(
    '*.cpp',
    '*.ui',
    '*.h'
  )

  on_config(function (target)
    target:set('rundir', os.projectdir())
  end)

  add_includedirs('.')

  add_rules(
    'qt.widgetapp',
    '@s21rules/cxx'
  )
  add_packages('qtgifimage', 'opengl')
  add_frameworks('QtCore', 'QtGui', 'QtWidgets', 'QtOpenGL')
  add_deps('s21lib')

  set_group('bin')
target_end()
