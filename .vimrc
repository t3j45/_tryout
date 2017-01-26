execute pathogen#infect()

filetype plugin indent on
syntax on

"Key-bindings
no <down> <Nop>
no <up> <Nop>
no <left> <Nop>
no <right> <Nop>

ino <down> <Nop>
ino <up> <Nop>
ino <left> <Nop>
ino <right> <Nop>

nnoremap G Gzz
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap J 7j
nnoremap K 7k
nnoremap <C-l> :nohlsearch<CR><C-l>
nnoremap <C-f> :bn<CR>
nnoremap <C-b> :bp<CR>
"nnoremap <C-w> :bd<CR>
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
inoremap <expr> j ((pumvisible())?("\<C-n>"):("j"))
inoremap <expr> k ((pumvisible())?("\<C-p>"):("k"))
nnoremap <C-s> :vimgrep /<cword>/gj 

" Hack to get alt key working 
set <M-b>=∫
set <M-f>=ƒ

cnoremap <C-a> <Home>
cnoremap <C-e> <End>
cnoremap <C-p> <Up>
cnoremap <C-n> <Down>
cnoremap <C-b> <Left>
cnoremap <C-f> <Right>
cnoremap <M-b> <S-Left>
cnoremap <M-f> <S-Right>

set backupdir=~/.vim/backup//
set directory=~/.vim/swap//
set undodir=~/.vim/undo//
"Search for files recursively in subdirectories
set path+=**

set backspace=indent,eol,start
set shiftwidth=4
set tabstop=4
set expandtab
set smarttab
set autoindent
set smartindent
set autoread
set number
set relativenumber
set mouse=a
set ignorecase
set smartcase
set showmatch
set incsearch
set scrolloff=3
set wildmenu
set wildignore+=pass,HDFC,xlink
set foldmethod=syntax
set cursorline

"CtrlP configuration
set runtimepath^=~/.vim/bundle/ctrlp.vim
noremap <C-g> :CtrlPFunky<CR>

"NERDTree configuration
noremap <C-n> :NERDTreeToggle<CR>
let g:NERDTreeChDIRMode=2
let NERDTreeShowHidden=1

"airline configuration
let g:airline#extensions#tabline#left_sep = ' '
let g:airline#extensions#tabline#left_alt_sep = '|'
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline#extensions#whitespace#checks=[]
set laststatus=2

"vim-notes configuration
let g:notes_directories = ['~/.vim/notes']
noremap <C-x> :SearchNotes<CR>

"theme configuration
colorscheme molokai
let g:molokai_original = 1
"let g:rehash256 = 1

"vim-cpp-enhanced-highlight configuration
"let g:cpp_class_scope_highlight = 1
"let g:cpp_experimental_template_highlight = 1
