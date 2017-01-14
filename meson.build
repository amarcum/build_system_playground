
project('tutorial', 'cpp')
jsondep = meson.get_compiler('cpp').find_library('jsoncpp', dirs: '/lib64')
jsondep = meson.get_compiler('cpp').find_library('pthread', dirs: '/lib64')
gtkdep  = dependency('gtk+-3.0')
executable('demo', 'main.cpp', dependencies : [ gtkdep, jsondep ])