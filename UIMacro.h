/**
 *  cissu 28/10/2012.
 *
 *  Copyright (c) 2010-2011, cissu
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *
 *  Neither the name of this project's author nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *  this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

//#define gx(view)                view.frame.origin.x//!获取view x坐标
//#define gy(view)                view.frame.origin.y//!获取view y坐标
//#define gw(view)                view.frame.size.width//!获取view 宽度
//#define gh(view)                view.frame.size.height//!获取view 高度
//#define gs(view)                view.frame.size//!获取view size
//#define go(view)                view.frame.origin//!获取view origin
/**
 @函数命名规则
 
 
 g->get (获取)
 s->set (设置)
 i->inside (内部相对布局,既被布局的视图已经addsubview到相对的视图之中)
 r->relative (同层次相对布局，既两个视图拥有同一个superview)
 c->center (中心,居中)
 x->x (x坐标)
 y->y (y坐标)
 r->right (右边，一般是x坐标)
 l->left (左边，一般是x坐标)
 b->bottom (底部边缘，一般是y坐标)
 t->top (顶部边缘，一般是y坐标)
 2->to (到)
 
 
 
 @示例
 sicx(UIView * parent, UIView * child, CGFloat offset);
 ||||
 sicx
 @brief 设置child的x坐标相对parent宽度居中，并且偏移offset个像素大小。 其中child视图被addsubview到parent视图中。
 
 siyb2b(UIView * parent, UIView * child, CGFloat offset);
 ||||||
 siyb2b
 @brief 设置child底部边缘距离parent底部边缘的大小，距离offset个像素大小，其中child视图被addsubview到parent视图中。
 
 srxr2r(UIView * primary, UIView * besetview, CGFloat offset);
 ||||||
 srxr2r
 @brief 设置besetview的右边缘相对primary的右边缘的距离，距离offset个像素大小。其中besetview视图和primary视图拥有同一个superview。
 
 */

//!获取view x坐标
static inline CGFloat gx(UIView * view)
{
    return view.frame.origin.x;
}

//!获取view y坐标
static inline CGFloat gy(UIView * view)
{
    return view.frame.origin.y;
}

//!获取view 宽度
static inline CGFloat gw(UIView * view)
{
    return view.frame.size.width;
}

//!获取view 高度
static inline CGFloat gh(UIView * view)
{
    return view.frame.size.height;
}

//!获取view size
static inline CGSize gs(UIView * view)
{
    return view.frame.size;
}

//!获取view origin
static inline CGPoint go(UIView * view)
{
    return view.frame.origin;
}

//!获取view的下边沿y坐标
static inline CGFloat gb(UIView * view)
{
    return (gy(view) + gh(view));
}

//!获取view的右边沿x坐标
static inline CGFloat gr(UIView * view)
{
    return (gx(view) + gw(view));
}

//!设置view size
static inline void ss(UIView * view, CGSize size)
{
    CGRect frame = view.frame;
    frame.size = size;
    view.frame = frame;
}

//!设置view origin
static inline void so(UIView * view, CGPoint origin)
{
    CGRect frame = view.frame;
    frame.origin = origin;
    view.frame = frame;
}

//!设置view x
static inline void sx(UIView * view, CGFloat x)
{
    CGRect frame = view.frame;
    frame.origin = CGPointMake(x,gy(view));
    view.frame = frame;
}

//!设置view y
static inline void sy(UIView * view, CGFloat y)
{
    CGRect frame = view.frame;
    frame.origin = CGPointMake(gx(view),y);
    view.frame = frame;
}

//!设置view宽
static inline void sw(UIView * view, CGFloat width)
{
    CGRect frame = view.frame;
    frame.size = CGSizeMake(width,gh(view));
    view.frame = frame;
}

//!设置view高
static inline void sh(UIView * view, CGFloat height)
{
    CGRect frame = view.frame;
    frame.size = CGSizeMake(gw(view),height);
    view.frame = frame;
}

//!缩放view宽高, scale分之一
static inline void svs(UIView * view, int scale)
{
    if (!scale)
        return;
    ss(view,CGSizeMake(gw(view)/scale,gh(view)/scale));
}


//!设置child相对父view右边x坐标偏移offset
static inline void sixr2r(UIView * parent, UIView * child, CGFloat offset)
{
    sx(child,gw(parent)-gw(child)-offset);
}
//!设置child相对父view左边x坐标
static inline void sixl2l(UIView * view, CGFloat y)
{
    sy(view,y);
}
//!设置child相对父view上边y坐标

static inline void siyt2t(UIView * view, CGFloat y)
{
    sx(view,y);
}

//!设置child相对父view下边y坐标偏移offset大小
static inline void siyb2b(UIView * parent, UIView * child, CGFloat offset)
{
    sy(child,gh(parent)-gh(child)-offset);
}

//!设置child相对self view 右边 x坐标size
//#define ssxr2l(child,size)          sixr2l(self,child,size)
//!设置child相对self view 下边 y坐标size
//#define ssyb2t(child,size)          siyb2t(self,child,size)

//!设置child相对父view中心x坐标偏移 offset大小
static inline void sicx(UIView * parent, UIView * child, CGFloat offset)
{
    sx(child,gw(parent)/2-gw(child)/2+offset);
}
//!设置child相对父view中心 y 坐标偏移offset大小
static inline void sicy(UIView * parent, UIView * child, CGFloat offset)
{
    sy(child,gh(parent)/2-gh(child)/2+offset);
}

//!设置child相对父view居中
static inline void sicc(UIView * parent,UIView * child)
{
    sicx(parent,child,0);
    sicy(parent,child,0);
}

#define sscx(child,size)            sicx(self,child,size)
#define sscy(child,size)            sicy(self,child,size)
#define sscc(child)                 sicc(self,child)

//!设置相对左边view x到右边viewx坐标偏移offset大小
static inline void srxl2l(UIView * left, UIView * right, CGFloat offset)
{
    sx(right,gx(left)+offset);
}
//!设置相对左边view 右边x到右边view x坐标偏移offset大小
static inline void srxr2l(UIView * left, UIView * right, CGFloat offset)
{
    sx(right,gx(left)+gw(left)+offset);
}
//!设置相对上边view 底部y到下边view的y坐标偏移offset大小
static inline void sryb2t(UIView * up, UIView * down, CGFloat offset)
{
    sy(down,gy(up)+gh(up)+offset);
}
//!设置相对上边view y到下边view的y坐标偏移offset大小
static inline void sryt2t(UIView * up, UIView * down, CGFloat offset)
{
    sy(down,gy(up)+offset);
}

static inline void srxr2r(UIView * primary, UIView * besetview, CGFloat offset)
{
    sx(besetview, gx(primary) + gw(primary) - gw(besetview) - offset);
}

static inline void srxl2r(UIView * primary, UIView * besetview, CGFloat offset)
{
    sx(besetview, gx(primary) - gw(besetview) - offset);
}

static inline void sryt2b (UIView * besetview, UIView * primary, CGFloat offset)
{
    sy(besetview, gy(primary)-gh(besetview)-offset);
}

static inline void sryb2b (UIView * up, UIView * down, CGFloat offset)
{
    sy(down, gb(up)-gh(down)-offset);
}

//!设置相对主view y中心的besetview的y坐标偏移offset大小
static inline void srcy(UIView * primary, UIView * besetview, CGFloat offset)
{
    sy(besetview, gy(primary) + gh(primary)/2 - gh(besetview)/2 + offset);
}
//!设置相对主view x中心besetview的 x坐标 偏移offset大小
static inline void srcx(UIView * primary, UIView * besetview, CGFloat offset)
{
    sx(besetview, gx(primary) + gw(primary)/2 - gw(besetview)/2 + offset);
}

static inline void srcc(UIView * primary, UIView * besetview)
{
    srcx(primary, besetview, 0);
    srcy(primary, besetview, 0);
}

