myapp_sources = [
  'main.c',
  'myapp-application.c',
  'myapp-window.c',
]

myapp_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

myapp_sources += gnome.compile_resources('myapp-resources',
  'myapp.gresource.xml',
  c_name: 'myapp'
)

executable('Memerist', myapp_sources,
  dependencies: myapp_deps,
       install: true,
)
