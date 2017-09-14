(function(){var k,aa="function"==typeof Object.create?Object.create:function(a){function b(){}
b.prototype=a;return new b},ba;
if("function"==typeof Object.setPrototypeOf)ba=Object.setPrototypeOf;else{var ca;a:{var da={va:!0},ea={};try{ea.__proto__=da;ca=ea.va;break a}catch(a){}ca=!1}ba=ca?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+" is not extensible");return a}:null}var fa=ba;
function n(a,b){a.prototype=aa(b.prototype);a.prototype.constructor=a;if(fa)fa(a,b);else for(var c in b)if("prototype"!=c)if(Object.defineProperties){var d=Object.getOwnPropertyDescriptor(b,c);d&&Object.defineProperty(a,c,d)}else a[c]=b[c];a.u=b.prototype}
for(var ha="function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){a!=Array.prototype&&a!=Object.prototype&&(a[b]=c.value)},ia="undefined"!=typeof window&&window===this?this:"undefined"!=typeof global&&null!=global?global:this,ja=function(){function a(){function a(){}
Reflect.construct(a,[],function(){});
return new a instanceof a}
if("undefined"!=typeof Reflect&&Reflect.construct){if(a())return Reflect.construct;var b=Reflect.construct;return function(a,d,e){a=b(a,d);e&&Reflect.setPrototypeOf(a,e.prototype);return a}}return function(a,b,e){void 0===e&&(e=a);
e=aa(e.prototype||Object.prototype);return Function.prototype.apply.call(a,e,b)||e}}(),ka=ia,la=["Reflect",
"construct"],ma=0;ma<la.length-1;ma++){var na=la[ma];na in ka||(ka[na]={});ka=ka[na]}var oa=la[la.length-1];ja!=ka[oa]&&null!=ja&&ha(ka,oa,{configurable:!0,writable:!0,value:ja});var p=this;function q(a){return void 0!==a}
function r(a){return"string"==typeof a}
function t(a,b,c){a=a.split(".");c=c||p;a[0]in c||!c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)!a.length&&q(b)?c[d]=b:c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}}
function u(a,b){for(var c=a.split("."),d=b||p,e=0;e<c.length;e++)if(d=d[c[e]],null==d)return null;return d}
function pa(){}
function qa(a){a.ia=void 0;a.getInstance=function(){return a.ia?a.ia:a.ia=new a}}
function ra(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("call"))return"function"}else return"null";
else if("function"==b&&"undefined"==typeof a.call)return"object";return b}
function sa(a){return"array"==ra(a)}
function ta(a){var b=ra(a);return"array"==b||"object"==b&&"number"==typeof a.length}
function ua(a){return"function"==ra(a)}
function va(a){var b=typeof a;return"object"==b&&null!=a||"function"==b}
var xa="closure_uid_"+(1E9*Math.random()>>>0),ya=0;function za(a,b,c){return a.call.apply(a.bind,arguments)}
function Aa(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var c=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(c,d);return a.apply(b,c)}}return function(){return a.apply(b,arguments)}}
function v(a,b,c){Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?v=za:v=Aa;return v.apply(null,arguments)}
function x(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var b=c.slice();b.push.apply(b,arguments);return a.apply(this,b)}}
var y=Date.now||function(){return+new Date};
function z(a,b){function c(){}
c.prototype=b.prototype;a.u=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.fb=function(a,c,f){for(var d=Array(arguments.length-2),e=2;e<arguments.length;e++)d[e-2]=arguments[e];return b.prototype[c].apply(a,d)}}
;function A(a){if(Error.captureStackTrace)Error.captureStackTrace(this,A);else{var b=Error().stack;b&&(this.stack=b)}a&&(this.message=String(a))}
z(A,Error);A.prototype.name="CustomError";var Ba=String.prototype.trim?function(a){return a.trim()}:function(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")};
function Ca(a,b){return a<b?-1:a>b?1:0}
function Da(a){for(var b=0,c=0;c<a.length;++c)b=31*b+a.charCodeAt(c)>>>0;return b}
;var B=Array.prototype.indexOf?function(a,b,c){return Array.prototype.indexOf.call(a,b,c)}:function(a,b,c){c=null==c?0:0>c?Math.max(0,a.length+c):c;
if(r(a))return r(b)&&1==b.length?a.indexOf(b,c):-1;for(;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1},C=Array.prototype.forEach?function(a,b,c){Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=r(a)?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},Ea=Array.prototype.filter?function(a,b,c){return Array.prototype.filter.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=[],f=0,g=r(a)?a.split(""):a,h=0;h<d;h++)if(h in g){var l=g[h];
b.call(c,l,h,a)&&(e[f++]=l)}return e},Fa=Array.prototype.map?function(a,b,c){return Array.prototype.map.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=Array(d),f=r(a)?a.split(""):a,g=0;g<d;g++)g in f&&(e[g]=b.call(c,f[g],g,a));
return e};
function Ga(a,b){a:{var c=a.length;for(var d=r(a)?a.split(""):a,e=0;e<c;e++)if(e in d&&b.call(void 0,d[e],e,a)){c=e;break a}c=-1}return 0>c?null:r(a)?a.charAt(c):a[c]}
function Ha(a,b){var c=B(a,b);0<=c&&Array.prototype.splice.call(a,c,1)}
function Ia(a){var b=a.length;if(0<b){for(var c=Array(b),d=0;d<b;d++)c[d]=a[d];return c}return[]}
function Ja(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(ta(d)){var e=a.length||0,f=d.length||0;a.length=e+f;for(var g=0;g<f;g++)a[e+g]=d[g]}else a.push(d)}}
;var Ka;a:{var La=p.navigator;if(La){var Ma=La.userAgent;if(Ma){Ka=Ma;break a}}Ka=""}function D(a){return-1!=Ka.indexOf(a)}
;function Na(a,b){var c=ta(b),d=c?b:arguments;for(c=c?0:1;c<d.length;c++){if(null==a)return;a=a[d[c]]}return a}
function Pa(a){var b=Qa,c;for(c in b)if(a.call(void 0,b[c],c,b))return c}
function Ra(a){for(var b in a)return!1;return!0}
function Sa(a,b){if(null!==a&&b in a)throw Error('The object already contains the key "'+b+'"');a[b]=!0}
function Ta(a){var b={},c;for(c in a)b[c]=a[c];return b}
var Ua="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" ");function Va(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<Ua.length;f++)c=Ua[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}}
;function Wa(a,b){var c=Xa;return Object.prototype.hasOwnProperty.call(c,a)?c[a]:c[a]=b(a)}
;var Ya=D("Opera"),E=D("Trident")||D("MSIE"),Za=D("Edge"),$a=D("Gecko")&&!(-1!=Ka.toLowerCase().indexOf("webkit")&&!D("Edge"))&&!(D("Trident")||D("MSIE"))&&!D("Edge"),ab=-1!=Ka.toLowerCase().indexOf("webkit")&&!D("Edge");function bb(){var a=p.document;return a?a.documentMode:void 0}
var cb;a:{var db="",eb=function(){var a=Ka;if($a)return/rv\:([^\);]+)(\)|;)/.exec(a);if(Za)return/Edge\/([\d\.]+)/.exec(a);if(E)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(ab)return/WebKit\/(\S+)/.exec(a);if(Ya)return/(?:Version)[ \/]?(\S+)/.exec(a)}();
eb&&(db=eb?eb[1]:"");if(E){var fb=bb();if(null!=fb&&fb>parseFloat(db)){cb=String(fb);break a}}cb=db}var gb=cb,Xa={};
function G(a){return Wa(a,function(){for(var b=0,c=Ba(String(gb)).split("."),d=Ba(String(a)).split("."),e=Math.max(c.length,d.length),f=0;0==b&&f<e;f++){var g=c[f]||"",h=d[f]||"";do{g=/(\d*)(\D*)(.*)/.exec(g)||["","","",""];h=/(\d*)(\D*)(.*)/.exec(h)||["","","",""];if(0==g[0].length&&0==h[0].length)break;b=Ca(0==g[1].length?0:parseInt(g[1],10),0==h[1].length?0:parseInt(h[1],10))||Ca(0==g[2].length,0==h[2].length)||Ca(g[2],h[2]);g=g[3];h=h[3]}while(0==b)}return 0<=b})}
var hb;var ib=p.document;hb=ib&&E?bb()||("CSS1Compat"==ib.compatMode?parseInt(gb,10):5):void 0;!$a&&!E||E&&9<=Number(hb)||$a&&G("1.9.1");E&&G("9");function jb(){this.b="";this.g=kb}
jb.prototype.ha=!0;jb.prototype.ga=function(){return this.b};
function lb(a){return a instanceof jb&&a.constructor===jb&&a.g===kb?a.b:"type_error:TrustedResourceUrl"}
var kb={};function H(){this.b="";this.g=mb}
H.prototype.ha=!0;H.prototype.ga=function(){return this.b};
function nb(a){return a instanceof H&&a.constructor===H&&a.g===mb?a.b:"type_error:SafeUrl"}
var ob=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i;function pb(a){if(a instanceof H)return a;a=a.ha?a.ga():String(a);ob.test(a)||(a="about:invalid#zClosurez");return qb(a)}
var mb={};function qb(a){var b=new H;b.b=a;return b}
qb("about:blank");function rb(){this.b=""}
rb.prototype.ha=!0;rb.prototype.ga=function(){return this.b};
function sb(a){var b=new rb;b.b=a;return b}
sb("<!DOCTYPE html>");sb("");sb("<br>");function tb(a,b){var c=b instanceof H?b:pb(b);a.href=nb(c)}
function ub(a,b){a.src=lb(b)}
;function vb(a,b){this.x=q(a)?a:0;this.y=q(b)?b:0}
vb.prototype.equals=function(a){return a instanceof vb&&(this==a?!0:this&&a?this.x==a.x&&this.y==a.y:!1)};
vb.prototype.ceil=function(){this.x=Math.ceil(this.x);this.y=Math.ceil(this.y);return this};
vb.prototype.floor=function(){this.x=Math.floor(this.x);this.y=Math.floor(this.y);return this};
vb.prototype.round=function(){this.x=Math.round(this.x);this.y=Math.round(this.y);return this};function wb(a,b){this.width=a;this.height=b}
k=wb.prototype;k.aspectRatio=function(){return this.width/this.height};
k.isEmpty=function(){return!(this.width*this.height)};
k.ceil=function(){this.width=Math.ceil(this.width);this.height=Math.ceil(this.height);return this};
k.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};
k.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};function xb(a){var b=document;return r(a)?b.getElementById(a):a}
function yb(a){if(!a)return null;if(a.firstChild)return a.firstChild;for(;a&&!a.nextSibling;)a=a.parentNode;return a?a.nextSibling:null}
function zb(a){if(!a)return null;if(!a.previousSibling)return a.parentNode;for(a=a.previousSibling;a&&a.lastChild;)a=a.lastChild;return a}
function Ab(a,b){for(var c=0;a;){if(b(a))return a;a=a.parentNode;c++}return null}
;function Bb(a){Cb();var b=new jb;b.b=a;return b}
var Cb=pa;var Db=document,I=window;function Eb(a){"number"==typeof a&&(a=Math.round(a)+"px");return a}
;var Fb=(new Date).getTime();function Gb(a){if(!a)return"";a=a.split("#")[0].split("?")[0];a=a.toLowerCase();0==a.indexOf("//")&&(a=window.location.protocol+a);/^[\w\-]*:\/\//.test(a)||(a=window.location.href);var b=a.substring(a.indexOf("://")+3),c=b.indexOf("/");-1!=c&&(b=b.substring(0,c));a=a.substring(0,a.indexOf("://"));if("http"!==a&&"https"!==a&&"chrome-extension"!==a&&"file"!==a&&"android-app"!==a&&"chrome-search"!==a)throw Error("Invalid URI scheme in origin");c="";var d=b.indexOf(":");if(-1!=d){var e=b.substring(d+
1);b=b.substring(0,d);if("http"===a&&"80"!==e||"https"===a&&"443"!==e)c=":"+e}return a+"://"+b+c}
;function Hb(){function a(){e[0]=1732584193;e[1]=4023233417;e[2]=2562383102;e[3]=271733878;e[4]=3285377520;w=m=0}
function b(a){for(var b=g,c=0;64>c;c+=4)b[c/4]=a[c]<<24|a[c+1]<<16|a[c+2]<<8|a[c+3];for(c=16;80>c;c++)a=b[c-3]^b[c-8]^b[c-14]^b[c-16],b[c]=(a<<1|a>>>31)&4294967295;a=e[0];var d=e[1],f=e[2],h=e[3],l=e[4];for(c=0;80>c;c++){if(40>c)if(20>c){var m=h^d&(f^h);var F=1518500249}else m=d^f^h,F=1859775393;else 60>c?(m=d&f|h&(d|f),F=2400959708):(m=d^f^h,F=3395469782);m=((a<<5|a>>>27)&4294967295)+m+l+F+b[c]&4294967295;l=h;h=f;f=(d<<30|d>>>2)&4294967295;d=a;a=m}e[0]=e[0]+a&4294967295;e[1]=e[1]+d&4294967295;e[2]=
e[2]+f&4294967295;e[3]=e[3]+h&4294967295;e[4]=e[4]+l&4294967295}
function c(a,c){if("string"===typeof a){a=unescape(encodeURIComponent(a));for(var d=[],e=0,g=a.length;e<g;++e)d.push(a.charCodeAt(e));a=d}c||(c=a.length);d=0;if(0==m)for(;d+64<c;)b(a.slice(d,d+64)),d+=64,w+=64;for(;d<c;)if(f[m++]=a[d++],w++,64==m)for(m=0,b(f);d+64<c;)b(a.slice(d,d+64)),d+=64,w+=64}
function d(){var a=[],d=8*w;56>m?c(h,56-m):c(h,64-(m-56));for(var g=63;56<=g;g--)f[g]=d&255,d>>>=8;b(f);for(g=d=0;5>g;g++)for(var l=24;0<=l;l-=8)a[d++]=e[g]>>l&255;return a}
for(var e=[],f=[],g=[],h=[128],l=1;64>l;++l)h[l]=0;var m,w;a();return{reset:a,update:c,digest:d,xa:function(){for(var a=d(),b="",c=0;c<a.length;c++)b+="0123456789ABCDEF".charAt(Math.floor(a[c]/16))+"0123456789ABCDEF".charAt(a[c]%16);return b}}}
;function Ib(a,b,c){var d=[],e=[];if(1==(sa(c)?2:1))return e=[b,a],C(d,function(a){e.push(a)}),Jb(e.join(" "));
var f=[],g=[];C(c,function(a){g.push(a.key);f.push(a.value)});
c=Math.floor((new Date).getTime()/1E3);e=0==f.length?[c,b,a]:[f.join(":"),c,b,a];C(d,function(a){e.push(a)});
a=Jb(e.join(" "));a=[c,a];0==g.length||a.push(g.join(""));return a.join("_")}
function Jb(a){var b=Hb();b.update(a);return b.xa().toLowerCase()}
;function Kb(a){this.b=a||{cookie:""}}
k=Kb.prototype;k.isEnabled=function(){return navigator.cookieEnabled};
k.set=function(a,b,c,d,e,f){if(/[;=\s]/.test(a))throw Error('Invalid cookie name "'+a+'"');if(/[;\r\n]/.test(b))throw Error('Invalid cookie value "'+b+'"');q(c)||(c=-1);e=e?";domain="+e:"";d=d?";path="+d:"";f=f?";secure":"";c=0>c?"":0==c?";expires="+(new Date(1970,1,1)).toUTCString():";expires="+(new Date(y()+1E3*c)).toUTCString();this.b.cookie=a+"="+b+e+d+c+f};
k.get=function(a,b){for(var c=a+"=",d=(this.b.cookie||"").split(";"),e=0,f;e<d.length;e++){f=Ba(d[e]);if(0==f.lastIndexOf(c,0))return f.substr(c.length);if(f==a)return""}return b};
k.remove=function(a,b,c){var d=q(this.get(a));this.set(a,"",0,b,c);return d};
k.isEmpty=function(){return!this.b.cookie};
k.clear=function(){for(var a=(this.b.cookie||"").split(";"),b=[],c=[],d,e,f=0;f<a.length;f++)e=Ba(a[f]),d=e.indexOf("="),-1==d?(b.push(""),c.push(e)):(b.push(e.substring(0,d)),c.push(e.substring(d+1)));for(a=b.length-1;0<=a;a--)this.remove(b[a])};
var Lb=new Kb("undefined"==typeof document?null:document);Lb.g=3950;function Mb(){var a=[],b=Gb(String(p.location.href)),c=p.__OVERRIDE_SID;null==c&&(c=(new Kb(document)).get("SID"));if(c&&(b=(c=0==b.indexOf("https:")||0==b.indexOf("chrome-extension:"))?p.__SAPISID:p.__APISID,null==b&&(b=(new Kb(document)).get(c?"SAPISID":"APISID")),b)){c=c?"SAPISIDHASH":"APISIDHASH";var d=String(p.location.href);return d&&b&&c?[c,Ib(Gb(d),b,a||null)].join(" "):null}return null}
;function Nb(a,b,c){this.h=c;this.f=a;this.i=b;this.g=0;this.b=null}
Nb.prototype.get=function(){if(0<this.g){this.g--;var a=this.b;this.b=a.next;a.next=null}else a=this.f();return a};
function Ob(a,b){a.i(b);a.g<a.h&&(a.g++,b.next=a.b,a.b=b)}
;function Pb(a){p.setTimeout(function(){throw a;},0)}
var Qb;
function Rb(){var a=p.MessageChannel;"undefined"===typeof a&&"undefined"!==typeof window&&window.postMessage&&window.addEventListener&&!D("Presto")&&(a=function(){var a=document.createElement("IFRAME");a.style.display="none";a.src="";document.documentElement.appendChild(a);var b=a.contentWindow;a=b.document;a.open();a.write("");a.close();var c="callImmediate"+Math.random(),d="file:"==b.location.protocol?"*":b.location.protocol+"//"+b.location.host;a=v(function(a){if(("*"==d||a.origin==d)&&a.data==
c)this.port1.onmessage()},this);
b.addEventListener("message",a,!1);this.port1={};this.port2={postMessage:function(){b.postMessage(c,d)}}});
if("undefined"!==typeof a&&!D("Trident")&&!D("MSIE")){var b=new a,c={},d=c;b.port1.onmessage=function(){if(q(c.next)){c=c.next;var a=c.na;c.na=null;a()}};
return function(a){d.next={na:a};d=d.next;b.port2.postMessage(0)}}return"undefined"!==typeof document&&"onreadystatechange"in document.createElement("SCRIPT")?function(a){var b=document.createElement("SCRIPT");
b.onreadystatechange=function(){b.onreadystatechange=null;b.parentNode.removeChild(b);b=null;a();a=null};
document.documentElement.appendChild(b)}:function(a){p.setTimeout(a,0)}}
;function Sb(){this.g=this.b=null}
var Ub=new Nb(function(){return new Tb},function(a){a.reset()},100);
Sb.prototype.remove=function(){var a=null;this.b&&(a=this.b,this.b=this.b.next,this.b||(this.g=null),a.next=null);return a};
function Tb(){this.next=this.scope=this.b=null}
Tb.prototype.set=function(a,b){this.b=a;this.scope=b;this.next=null};
Tb.prototype.reset=function(){this.next=this.scope=this.b=null};function Vb(a,b){Wb||Xb();Yb||(Wb(),Yb=!0);var c=Zb,d=Ub.get();d.set(a,b);c.g?c.g.next=d:c.b=d;c.g=d}
var Wb;function Xb(){if(-1!=String(p.Promise).indexOf("[native code]")){var a=p.Promise.resolve(void 0);Wb=function(){a.then($b)}}else Wb=function(){var a=$b;
!ua(p.setImmediate)||p.Window&&p.Window.prototype&&!D("Edge")&&p.Window.prototype.setImmediate==p.setImmediate?(Qb||(Qb=Rb()),Qb(a)):p.setImmediate(a)}}
var Yb=!1,Zb=new Sb;function $b(){for(var a;a=Zb.remove();){try{a.b.call(a.scope)}catch(b){Pb(b)}Ob(Ub,a)}Yb=!1}
;var ac=D("Firefox"),bc=(D("Chrome")||D("CriOS"))&&!D("Edge");function J(){this.g=this.g;this.F=this.F}
J.prototype.g=!1;J.prototype.dispose=function(){this.g||(this.g=!0,this.l())};
function cc(a,b){a.g?q(void 0)?b.call(void 0):b():(a.F||(a.F=[]),a.F.push(q(void 0)?v(b,void 0):b))}
J.prototype.l=function(){if(this.F)for(;this.F.length;)this.F.shift()()};
function dc(a){a&&"function"==typeof a.dispose&&a.dispose()}
function ec(a){for(var b=0,c=arguments.length;b<c;++b){var d=arguments[b];ta(d)?ec.apply(null,d):dc(d)}}
;function fc(a){if(a.classList)return a.classList;a=a.className;return r(a)&&a.match(/\S+/g)||[]}
function gc(a,b){if(a.classList)var c=a.classList.contains(b);else c=fc(a),c=0<=B(c,b);return c}
function hc(){var a=document.body;a.classList?a.classList.remove("inverted-hdpi"):gc(a,"inverted-hdpi")&&(a.className=Ea(fc(a),function(a){return"inverted-hdpi"!=a}).join(" "))}
;var ic="StopIteration"in p?p.StopIteration:{message:"StopIteration",stack:""};function jc(){}
jc.prototype.next=function(){throw ic;};
jc.prototype.X=function(){return this};
function kc(a){if(a instanceof jc)return a;if("function"==typeof a.X)return a.X(!1);if(ta(a)){var b=0,c=new jc;c.next=function(){for(;;){if(b>=a.length)throw ic;if(b in a)return a[b++];b++}};
return c}throw Error("Not implemented");}
function lc(a,b){if(ta(a))try{C(a,b,void 0)}catch(c){if(c!==ic)throw c;}else{a=kc(a);try{for(;;)b.call(void 0,a.next(),void 0,a)}catch(c){if(c!==ic)throw c;}}}
function mc(a){if(ta(a))return Ia(a);a=kc(a);var b=[];lc(a,function(a){b.push(a)});
return b}
;E&&G("9");!ab||G("528");$a&&G("1.9b")||E&&G("8")||Ya&&G("9.5")||ab&&G("528");$a&&!G("8")||E&&G("9");function nc(a){var b=[];oc(new pc,a,b);return b.join("")}
function pc(){}
function oc(a,b,c){if(null==b)c.push("null");else{if("object"==typeof b){if(sa(b)){var d=b;b=d.length;c.push("[");for(var e="",f=0;f<b;f++)c.push(e),oc(a,d[f],c),e=",";c.push("]");return}if(b instanceof String||b instanceof Number||b instanceof Boolean)b=b.valueOf();else{c.push("{");e="";for(d in b)Object.prototype.hasOwnProperty.call(b,d)&&(f=b[d],"function"!=typeof f&&(c.push(e),qc(d,c),c.push(":"),oc(a,f,c),e=","));c.push("}");return}}switch(typeof b){case "string":qc(b,c);break;case "number":c.push(isFinite(b)&&
!isNaN(b)?String(b):"null");break;case "boolean":c.push(String(b));break;case "function":c.push("null");break;default:throw Error("Unknown type: "+typeof b);}}}
var rc={'"':'\\"',"\\":"\\\\","/":"\\/","\b":"\\b","\f":"\\f","\n":"\\n","\r":"\\r","\t":"\\t","\x0B":"\\u000b"},sc=/\uffff/.test("\uffff")?/[\\\"\x00-\x1f\x7f-\uffff]/g:/[\\\"\x00-\x1f\x7f-\xff]/g;function qc(a,b){b.push('"',a.replace(sc,function(a){var b=rc[a];b||(b="\\u"+(a.charCodeAt(0)|65536).toString(16).substr(1),rc[a]=b);return b}),'"')}
;function tc(a){a.prototype.then=a.prototype.then;a.prototype.$goog_Thenable=!0}
function uc(a){if(!a)return!1;try{return!!a.$goog_Thenable}catch(b){return!1}}
;function K(a,b){this.b=0;this.m=void 0;this.h=this.g=this.f=null;this.i=this.j=!1;if(a!=pa)try{var c=this;a.call(b,function(a){vc(c,2,a)},function(a){vc(c,3,a)})}catch(d){vc(this,3,d)}}
function wc(){this.next=this.context=this.g=this.f=this.b=null;this.h=!1}
wc.prototype.reset=function(){this.context=this.g=this.f=this.b=null;this.h=!1};
var xc=new Nb(function(){return new wc},function(a){a.reset()},100);
function yc(a,b,c){var d=xc.get();d.f=a;d.g=b;d.context=c;return d}
function zc(a){return new K(function(b,c){c(a)})}
K.prototype.then=function(a,b,c){return Ac(this,ua(a)?a:null,ua(b)?b:null,c)};
tc(K);function Bc(a,b){return Ac(a,null,b,void 0)}
K.prototype.cancel=function(a){0==this.b&&Vb(function(){var b=new Cc(a);Dc(this,b)},this)};
function Dc(a,b){if(0==a.b)if(a.f){var c=a.f;if(c.g){for(var d=0,e=null,f=null,g=c.g;g&&(g.h||(d++,g.b==a&&(e=g),!(e&&1<d)));g=g.next)e||(f=g);e&&(0==c.b&&1==d?Dc(c,b):(f?(d=f,d.next==c.h&&(c.h=d),d.next=d.next.next):Ec(c),Fc(c,e,3,b)))}a.f=null}else vc(a,3,b)}
function Gc(a,b){a.g||2!=a.b&&3!=a.b||Hc(a);a.h?a.h.next=b:a.g=b;a.h=b}
function Ac(a,b,c,d){var e=yc(null,null,null);e.b=new K(function(a,g){e.f=b?function(c){try{var e=b.call(d,c);a(e)}catch(m){g(m)}}:a;
e.g=c?function(b){try{var e=c.call(d,b);!q(e)&&b instanceof Cc?g(b):a(e)}catch(m){g(m)}}:g});
e.b.f=a;Gc(a,e);return e.b}
K.prototype.w=function(a){this.b=0;vc(this,2,a)};
K.prototype.A=function(a){this.b=0;vc(this,3,a)};
function vc(a,b,c){if(0==a.b){a===c&&(b=3,c=new TypeError("Promise cannot resolve to itself"));a.b=1;a:{var d=c,e=a.w,f=a.A;if(d instanceof K){Gc(d,yc(e||pa,f||null,a));var g=!0}else if(uc(d))d.then(e,f,a),g=!0;else{if(va(d))try{var h=d.then;if(ua(h)){Ic(d,h,e,f,a);g=!0;break a}}catch(l){f.call(a,l);g=!0;break a}g=!1}}g||(a.m=c,a.b=b,a.f=null,Hc(a),3!=b||c instanceof Cc||Jc(a,c))}}
function Ic(a,b,c,d,e){function f(a){h||(h=!0,d.call(e,a))}
function g(a){h||(h=!0,c.call(e,a))}
var h=!1;try{b.call(a,g,f)}catch(l){f(l)}}
function Hc(a){a.j||(a.j=!0,Vb(a.o,a))}
function Ec(a){var b=null;a.g&&(b=a.g,a.g=b.next,b.next=null);a.g||(a.h=null);return b}
K.prototype.o=function(){for(var a;a=Ec(this);)Fc(this,a,this.b,this.m);this.j=!1};
function Fc(a,b,c,d){if(3==c&&b.g&&!b.h)for(;a&&a.i;a=a.f)a.i=!1;if(b.b)b.b.f=null,Kc(b,c,d);else try{b.h?b.f.call(b.context):Kc(b,c,d)}catch(e){Lc.call(null,e)}Ob(xc,b)}
function Kc(a,b,c){2==b?a.f.call(a.context,c):a.g&&a.g.call(a.context,c)}
function Jc(a,b){a.i=!0;Vb(function(){a.i&&Lc.call(null,b)})}
var Lc=Pb;function Cc(a){A.call(this,a)}
z(Cc,A);Cc.prototype.name="cancel";function L(a){J.call(this);this.j=1;this.h=[];this.i=0;this.b=[];this.f={};this.m=!!a}
z(L,J);k=L.prototype;k.subscribe=function(a,b,c){var d=this.f[a];d||(d=this.f[a]=[]);var e=this.j;this.b[e]=a;this.b[e+1]=b;this.b[e+2]=c;this.j=e+3;d.push(e);return e};
function Mc(a,b,c,d){if(b=a.f[b]){var e=a.b;(b=Ga(b,function(a){return e[a+1]==c&&e[a+2]==d}))&&a.D(b)}}
k.D=function(a){var b=this.b[a];if(b){var c=this.f[b];0!=this.i?(this.h.push(a),this.b[a+1]=pa):(c&&Ha(c,a),delete this.b[a],delete this.b[a+1],delete this.b[a+2])}return!!b};
k.K=function(a,b){var c=this.f[a];if(c){for(var d=Array(arguments.length-1),e=1,f=arguments.length;e<f;e++)d[e-1]=arguments[e];if(this.m)for(e=0;e<c.length;e++){var g=c[e];Nc(this.b[g+1],this.b[g+2],d)}else{this.i++;try{for(e=0,f=c.length;e<f;e++)g=c[e],this.b[g+1].apply(this.b[g+2],d)}finally{if(this.i--,0<this.h.length&&0==this.i)for(;c=this.h.pop();)this.D(c)}}return 0!=e}return!1};
function Nc(a,b,c){Vb(function(){a.apply(b,c)})}
k.clear=function(a){if(a){var b=this.f[a];b&&(C(b,this.D,this),delete this.f[a])}else this.b.length=0,this.f={}};
k.l=function(){L.u.l.call(this);this.clear();this.h.length=0};function Oc(a){this.b=a}
Oc.prototype.set=function(a,b){q(b)?this.b.set(a,nc(b)):this.b.remove(a)};
Oc.prototype.get=function(a){try{var b=this.b.get(a)}catch(c){return}if(null!==b)try{return JSON.parse(b)}catch(c){throw"Storage: Invalid value was encountered";}};
Oc.prototype.remove=function(a){this.b.remove(a)};function Pc(a){this.b=a}
z(Pc,Oc);function Qc(a){this.data=a}
function Rc(a){return!q(a)||a instanceof Qc?a:new Qc(a)}
Pc.prototype.set=function(a,b){Pc.u.set.call(this,a,Rc(b))};
Pc.prototype.g=function(a){a=Pc.u.get.call(this,a);if(!q(a)||a instanceof Object)return a;throw"Storage: Invalid value was encountered";};
Pc.prototype.get=function(a){if(a=this.g(a)){if(a=a.data,!q(a))throw"Storage: Invalid value was encountered";}else a=void 0;return a};function M(a){this.b=a}
z(M,Pc);M.prototype.set=function(a,b,c){if(b=Rc(b)){if(c){if(c<y()){M.prototype.remove.call(this,a);return}b.expiration=c}b.creation=y()}M.u.set.call(this,a,b)};
M.prototype.g=function(a,b){var c=M.u.g.call(this,a);if(c){var d;if(d=!b){d=c.creation;var e=c.expiration;d=!!e&&e<y()||!!d&&d>y()}if(d)M.prototype.remove.call(this,a);else return c}};function Sc(a){this.b=a}
z(Sc,M);function Tc(){}
;function Uc(){}
z(Uc,Tc);Uc.prototype.clear=function(){var a=mc(this.X(!0)),b=this;C(a,function(a){b.remove(a)})};function Vc(a){this.b=a}
z(Vc,Uc);k=Vc.prototype;k.isAvailable=function(){if(!this.b)return!1;try{return this.b.setItem("__sak","1"),this.b.removeItem("__sak"),!0}catch(a){return!1}};
k.set=function(a,b){try{this.b.setItem(a,b)}catch(c){if(0==this.b.length)throw"Storage mechanism: Storage disabled";throw"Storage mechanism: Quota exceeded";}};
k.get=function(a){a=this.b.getItem(a);if(!r(a)&&null!==a)throw"Storage mechanism: Invalid value was encountered";return a};
k.remove=function(a){this.b.removeItem(a)};
k.X=function(a){var b=0,c=this.b,d=new jc;d.next=function(){if(b>=c.length)throw ic;var d=c.key(b++);if(a)return d;d=c.getItem(d);if(!r(d))throw"Storage mechanism: Invalid value was encountered";return d};
return d};
k.clear=function(){this.b.clear()};
k.key=function(a){return this.b.key(a)};function Wc(){var a=null;try{a=window.localStorage||null}catch(b){}this.b=a}
z(Wc,Vc);function Xc(){var a=null;try{a=window.sessionStorage||null}catch(b){}this.b=a}
z(Xc,Vc);var Yc=/^(?:([^:/?#.]+):)?(?:\/\/(?:([^/?#]*)@)?([^/#?]*?)(?::([0-9]+))?(?=[/#?]|$))?([^?#]+)?(?:\?([^#]*))?(?:#([\s\S]*))?$/;function N(a){return a.match(Yc)}
function Zc(a){return a?decodeURI(a):a}
function $c(a,b,c){if(sa(b))for(var d=0;d<b.length;d++)$c(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))}
function ad(a){var b=[],c;for(c in a)$c(c,a[c],b);return b.join("&")}
function bd(a,b){var c=ad(b);if(c){var d=a.indexOf("#");0>d&&(d=a.length);var e=a.indexOf("?");if(0>e||e>d){e=d;var f=""}else f=a.substring(e+1,d);d=[a.substr(0,e),f,a.substr(d)];e=d[1];d[1]=c?e?e+"&"+c:c:e;c=d[0]+(d[1]?"?"+d[1]:"")+d[2]}else c=a;return c}
;var cd=!1,dd="";function ed(a){a=a.match(/[\d]+/g);if(!a)return"";a.length=3;return a.join(".")}
(function(){if(navigator.plugins&&navigator.plugins.length){var a=navigator.plugins["Shockwave Flash"];if(a&&(cd=!0,a.description)){dd=ed(a.description);return}if(navigator.plugins["Shockwave Flash 2.0"]){cd=!0;dd="2.0.0.11";return}}if(navigator.mimeTypes&&navigator.mimeTypes.length&&(a=navigator.mimeTypes["application/x-shockwave-flash"],cd=!(!a||!a.enabledPlugin))){dd=ed(a.enabledPlugin.description);return}try{var b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7");cd=!0;dd=ed(b.GetVariable("$version"));
return}catch(c){}try{b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");cd=!0;dd="6.0.21";return}catch(c){}try{b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash"),cd=!0,dd=ed(b.GetVariable("$version"))}catch(c){}})();
var fd=cd,gd=dd;function hd(a,b){if(1<b.length)a[b[0]]=b[1];else{var c=b[0],d;for(d in c)a[d]=c[d]}}
var O=window.performance&&window.performance.timing&&window.performance.now?function(){return window.performance.timing.navigationStart+window.performance.now()}:function(){return(new Date).getTime()},id="Microsoft Internet Explorer"==navigator.appName;var jd=window.yt&&window.yt.config_||window.ytcfg&&window.ytcfg.data_||{};t("yt.config_",jd,void 0);function P(a){hd(jd,arguments)}
function Q(a,b){return a in jd?jd[a]:b}
function R(a){return Q(a,void 0)}
;function kd(a){return a&&window.yterr?function(){try{return a.apply(this,arguments)}catch(b){S(b)}}:a}
function S(a,b){var c=u("yt.logging.errors.log");c?c(a,b,void 0,void 0,void 0):(c=Q("ERRORS",[]),c.push([a,b,void 0,void 0,void 0]),P("ERRORS",c))}
;function T(a){return Q("EXPERIMENT_FLAGS",{})[a]}
;function ld(a){a&&(a.dataset?a.dataset[md("loaded")]="true":a.setAttribute("data-loaded","true"))}
function nd(a,b){return a?a.dataset?a.dataset[md(b)]:a.getAttribute("data-"+b):null}
var od={};function md(a){return od[a]||(od[a]=String(a).replace(/\-([a-z])/g,function(a,c){return c.toUpperCase()}))}
;function U(a,b){ua(a)&&(a=kd(a));return window.setTimeout(a,b)}
;var pd=u("ytPubsubPubsubInstance")||new L;L.prototype.subscribe=L.prototype.subscribe;L.prototype.unsubscribeByKey=L.prototype.D;L.prototype.publish=L.prototype.K;L.prototype.clear=L.prototype.clear;t("ytPubsubPubsubInstance",pd,void 0);var sd=u("ytPubsubPubsubSubscribedKeys")||{};t("ytPubsubPubsubSubscribedKeys",sd,void 0);var td=u("ytPubsubPubsubTopicToKeys")||{};t("ytPubsubPubsubTopicToKeys",td,void 0);var ud=u("ytPubsubPubsubIsSynchronous")||{};t("ytPubsubPubsubIsSynchronous",ud,void 0);
function vd(a,b){var c=wd();if(c){var d=c.subscribe(a,function(){var c=arguments;var f=function(){sd[d]&&b.apply(window,c)};
try{ud[a]?f():U(f,0)}catch(g){S(g)}},void 0);
sd[d]=!0;td[a]||(td[a]=[]);td[a].push(d);return d}return 0}
function xd(a){var b=wd();b&&("number"==typeof a?a=[a]:r(a)&&(a=[parseInt(a,10)]),C(a,function(a){b.unsubscribeByKey(a);delete sd[a]}))}
function yd(a,b){var c=wd();c&&c.publish.apply(c,arguments)}
function zd(a){var b=wd();if(b)if(b.clear(a),a)Ad(a);else for(var c in td)Ad(c)}
function wd(){return u("ytPubsubPubsubInstance")}
function Ad(a){td[a]&&(a=td[a],C(a,function(a){sd[a]&&delete sd[a]}),a.length=0)}
;var Bd=/\.vflset|-vfl[a-zA-Z0-9_+=-]+/,Cd=/-[a-zA-Z]{2,3}_[a-zA-Z]{2,3}(?=(\/|$))/;function Dd(a,b){if(window.spf){var c="";if(a){var d=a.indexOf("jsbin/"),e=a.lastIndexOf(".js"),f=d+6;-1<d&&-1<e&&e>f&&(c=a.substring(f,e),c=c.replace(Bd,""),c=c.replace(Cd,""),c=c.replace("debug-",""),c=c.replace("tracing-",""))}spf.script.load(a,c,b)}else Ed(a,b)}
function Ed(a,b){var c=Fd(a),d=document.getElementById(c),e=d&&nd(d,"loaded"),f=d&&!e;if(e)b&&b();else{if(b){e=vd(c,b);var g=""+(b[xa]||(b[xa]=++ya));Gd[g]=e}f||(d=Hd(a,c,function(){nd(d,"loaded")||(ld(d),yd(c),U(x(zd,c),0))}))}}
function Hd(a,b,c){var d=document.createElement("SCRIPT");d.id=b;d.onload=function(){c&&setTimeout(c,0)};
d.onreadystatechange=function(){switch(d.readyState){case "loaded":case "complete":d.onload()}};
ub(d,Bb(a));a=document.getElementsByTagName("head")[0]||document.body;a.insertBefore(d,a.firstChild);return d}
function Id(a){a=Fd(a);var b=document.getElementById(a);b&&(zd(a),b.parentNode.removeChild(b))}
function Jd(a,b){if(a&&b){var c=""+(b[xa]||(b[xa]=++ya));(c=Gd[c])&&xd(c)}}
function Fd(a){var b=document.createElement("a");tb(b,a);a=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"js-"+Da(a)}
var Gd={};var Kd=null;function Ld(){var a=Q("BG_I",null),b=Q("BG_IU",null),c=Q("BG_P",void 0);b?Dd(b,function(){window.botguard?Md(c):(Id(b),S(Error("Unable to load Botguard from "+b),"WARNING"))}):a&&(eval(a),Md(c))}
function Md(a){Kd=new window.botguard.bg(a);T("botguard_periodic_refresh")&&O()}
function Nd(){return null!=Kd}
function Od(){return Kd?Kd.invoke():null}
;y();var Pd=q(XMLHttpRequest)?function(){return new XMLHttpRequest}:q(ActiveXObject)?function(){return new ActiveXObject("Microsoft.XMLHTTP")}:null;
function Qd(){if(!Pd)return null;var a=Pd();return"open"in a?a:null}
function Rd(a){switch(a&&"status"in a?a.status:-1){case 200:case 201:case 202:case 203:case 204:case 205:case 206:case 304:return!0;default:return!1}}
;function Sd(a){"?"==a.charAt(0)&&(a=a.substr(1));a=a.split("&");for(var b={},c=0,d=a.length;c<d;c++){var e=a[c].split("=");if(1==e.length&&e[0]||2==e.length){var f=decodeURIComponent((e[0]||"").replace(/\+/g," "));e=decodeURIComponent((e[1]||"").replace(/\+/g," "));f in b?sa(b[f])?Ja(b[f],e):b[f]=[b[f],e]:b[f]=e}}return b}
function Td(a,b){var c=a.split("#",2);a=c[0];c=1<c.length?"#"+c[1]:"";var d=a.split("?",2);a=d[0];d=Sd(d[1]||"");for(var e in b)d[e]=b[e];return bd(a,d)+c}
;var Ud={"X-Goog-Visitor-Id":"SANDBOXED_VISITOR_ID","X-YouTube-Client-Name":"INNERTUBE_CONTEXT_CLIENT_NAME","X-YouTube-Client-Version":"INNERTUBE_CONTEXT_CLIENT_VERSION","X-Youtube-Identity-Token":"ID_TOKEN","X-YouTube-Page-CL":"PAGE_CL","X-YouTube-Page-Label":"PAGE_BUILD_LABEL","X-YouTube-Variants-Checksum":"VARIANTS_CHECKSUM"},Vd=!1;
function Wd(a,b){b=void 0===b?{}:b;if(!c)var c=window.location.href;var d=N(a)[1]||null,e=Zc(N(a)[3]||null);d&&e?(d=c,c=N(a),d=N(d),c=c[3]==d[3]&&c[1]==d[1]&&c[4]==d[4]):c=e?Zc(N(c)[3]||null)==e&&(Number(N(c)[4]||null)||null)==(Number(N(a)[4]||null)||null):!0;for(var f in Ud){if((e=d=Q(Ud[f]))&&!(e=c)){e=f;var g=Q("CORS_HEADER_WHITELIST")||{},h=Zc(N(a)[3]||null);e=h?(g=g[h])?0<=B(g,e):!1:!0}e&&(b[f]=d)}return b}
function Xd(a,b){var c=Q("XSRF_FIELD_NAME",void 0),d;b.headers&&(d=b.headers["Content-Type"]);return!b.hb&&(!Zc(N(a)[3]||null)||b.withCredentials||Zc(N(a)[3]||null)==document.location.hostname)&&"POST"==b.method&&(!d||"application/x-www-form-urlencoded"==d)&&!(b.B&&b.B[c])}
function Yd(a,b){var c=b.format||"JSON";b.Ca&&(a=document.location.protocol+"//"+document.location.hostname+(document.location.port?":"+document.location.port:"")+a);var d=Q("XSRF_FIELD_NAME",void 0),e=Q("XSRF_TOKEN",void 0),f=b.ab;f&&(f[d]&&delete f[d],a=Td(a,f||{}));f=b.postBody||"";var g=b.B;Xd(a,b)&&(g||(g={}),g[d]=e);g&&r(f)&&(d=Sd(f),Va(d,g),f=b.qa&&"JSON"==b.qa?JSON.stringify(d):ad(d));d=f||g&&!Ra(g);!Vd&&d&&"POST"!=b.method&&(Vd=!0,S(Error("AJAX request with postData should use POST")));var h=
!1,l,m=Zd(a,function(a){if(!h){h=!0;l&&window.clearTimeout(l);var d=Rd(a),e=null;if(d||400<=a.status&&500>a.status)e=$d(c,a,b.gb);if(d)a:if(204==a.status)d=!0;else{switch(c){case "XML":d=0==parseInt(e&&e.return_code,10);break a;case "RAW":d=!0;break a}d=!!e}e=e||{};var f=b.context||p;d?b.P&&b.P.call(f,a,e):b.onError&&b.onError.call(f,a,e);b.Ia&&b.Ia.call(f,a,e)}},b.method,f,b.headers,b.responseType,b.withCredentials);
b.Z&&0<b.timeout&&(l=U(function(){h||(h=!0,m.abort(),window.clearTimeout(l),b.Z.call(b.context||p,m))},b.timeout))}
function $d(a,b,c){var d=null;switch(a){case "JSON":a=b.responseText;b=b.getResponseHeader("Content-Type")||"";a&&0<=b.indexOf("json")&&(d=JSON.parse(a));break;case "XML":if(b=(b=b.responseXML)?ae(b):null)d={},C(b.getElementsByTagName("*"),function(a){d[a.tagName]=be(a)})}c&&ce(d);
return d}
function ce(a){if(va(a))for(var b in a){var c;(c="html_content"==b)||(c=b.length-5,c=0<=c&&b.indexOf("_html",c)==c);if(c){c=b;var d=sb(a[b]);a[c]=d}else ce(a[b])}}
function ae(a){return a?(a=("responseXML"in a?a.responseXML:a).getElementsByTagName("root"))&&0<a.length?a[0]:null:null}
function be(a){var b="";C(a.childNodes,function(a){b+=a.nodeValue});
return b}
function de(a,b){b.method="POST";b.B||(b.B={});Yd(a,b)}
function Zd(a,b,c,d,e,f,g){function h(){4==(l&&"readyState"in l?l.readyState:0)&&b&&kd(b)(l)}
c=void 0===c?"GET":c;d=void 0===d?"":d;var l=Qd();if(!l)return null;"onloadend"in l?l.addEventListener("loadend",h,!1):l.onreadystatechange=h;l.open(c,a,!0);f&&(l.responseType=f);g&&(l.withCredentials=!0);c="POST"==c;if(e=Wd(a,e))for(var m in e)l.setRequestHeader(m,e[m]),"content-type"==m.toLowerCase()&&(c=!1);c&&l.setRequestHeader("Content-Type","application/x-www-form-urlencoded");l.send(d);return l}
;var ee={},fe=0;function ge(a,b){a&&(Q("USE_NET_AJAX_FOR_PING_TRANSPORT",!1)?Zd(a,b,"GET","",void 0):he(a,b))}
function he(a,b){var c=new Image,d=""+fe++;ee[d]=c;c.onload=c.onerror=function(){b&&ee[d]&&b();delete ee[d]};
c.src=a}
;var ie={},je=0;
function ke(a,b,c,d,e,f){f=f||{};f.name=c||Q("INNERTUBE_CONTEXT_CLIENT_NAME",1);f.version=d||Q("INNERTUBE_CONTEXT_CLIENT_VERSION",void 0);b=void 0===b?"ERROR":b;e=void 0===e?!1:e;e=window&&window.yterr||(void 0===e?!1:e)||!1;if(a&&e&&!(5<=je)){e=a.stacktrace;c=a.columnNumber;d=u("window.location.href");if(r(a))a={message:a,name:"Unknown error",lineNumber:"Not available",fileName:d,stack:"Not available"};else{var g=!1;try{var h=a.lineNumber||a.line||"Not available"}catch(F){h="Not available",g=!0}try{var l=
a.fileName||a.filename||a.sourceURL||p.$googDebugFname||d}catch(F){l="Not available",g=!0}a=!g&&a.lineNumber&&a.fileName&&a.stack&&a.message&&a.name?a:{message:a.message||"Not available",name:a.name||"UnknownError",lineNumber:h,fileName:l,stack:a.stack||"Not available"}}e=e||a.stack;h=a.lineNumber.toString();isNaN(h)||isNaN(c)||(h=h+":"+c);if(!(ie[a.message]||0<=e.indexOf("/YouTubeCenter.js")||0<=e.indexOf("/mytube.js"))){l=e;h={ab:{a:"logerror",t:"jserror",type:a.name,msg:a.message.substr(0,1E3),
line:h,level:void 0===b?"ERROR":b,"client.name":f.name},B:{url:Q("PAGE_NAME",window.location.href),file:a.fileName},method:"POST"};f.version&&(h["client.version"]=f.version);l&&(h.B.stack=l);for(var m in f)h.B["client."+m]=f[m];if(m=Q("LATEST_ECATCHER_SERVICE_TRACKING_PARAMS",void 0))for(var w in m)h.B[w]=m[w];Yd("/error_204",h);ie[a.message]=!0;je++}}}
;var le=window.yt&&window.yt.msgs_||window.ytcfg&&window.ytcfg.msgs||{};t("yt.msgs_",le,void 0);function me(a){hd(le,arguments)}
;function ne(a,b){var c=5E3;isNaN(c)&&(c=void 0);var d=u("yt.scheduler.instance.addJob");return d?d(a,b,c):void 0===c?(a(),NaN):U(a,c||0)}
function oe(a){if(!isNaN(a)){var b=u("yt.scheduler.instance.cancelJob");b?b(a):window.clearTimeout(a)}}
;var pe=[],qe=!1;function re(){function a(){qe=!0;"google_ad_status"in window?P("DCLKSTAT",1):P("DCLKSTAT",2)}
Dd("//static.doubleclick.net/instream/ad_status.js",a);pe.push(ne(function(){qe||"google_ad_status"in window||(Jd("//static.doubleclick.net/instream/ad_status.js",a),P("DCLKSTAT",3))},1))}
function se(){return parseInt(Q("DCLKSTAT",0),10)}
;var te=0;t("ytDomDomGetNextId",u("ytDomDomGetNextId")||function(){return++te},void 0);var ue={stopImmediatePropagation:1,stopPropagation:1,preventMouseEvent:1,preventManipulation:1,preventDefault:1,layerX:1,layerY:1,screenX:1,screenY:1,scale:1,rotation:1,webkitMovementX:1,webkitMovementY:1};
function ve(a){this.type="";this.state=this.source=this.data=this.currentTarget=this.relatedTarget=this.target=null;this.charCode=this.keyCode=0;this.shiftKey=this.ctrlKey=this.altKey=!1;this.clientY=this.clientX=0;this.changedTouches=this.touches=null;if(a=a||window.event){this.event=a;for(var b in a)b in ue||(this[b]=a[b]);(b=a.target||a.srcElement)&&3==b.nodeType&&(b=b.parentNode);this.target=b;if(b=a.relatedTarget)try{b=b.nodeName?b:null}catch(c){b=null}else"mouseover"==this.type?b=a.fromElement:
"mouseout"==this.type&&(b=a.toElement);this.relatedTarget=b;this.clientX=void 0!=a.clientX?a.clientX:a.pageX;this.clientY=void 0!=a.clientY?a.clientY:a.pageY;this.keyCode=a.keyCode?a.keyCode:a.which;this.charCode=a.charCode||("keypress"==this.type?this.keyCode:0);this.altKey=a.altKey;this.ctrlKey=a.ctrlKey;this.shiftKey=a.shiftKey}}
ve.prototype.preventDefault=function(){this.event&&(this.event.returnValue=!1,this.event.preventDefault&&this.event.preventDefault())};
ve.prototype.stopPropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopPropagation&&this.event.stopPropagation())};
ve.prototype.stopImmediatePropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopImmediatePropagation&&this.event.stopImmediatePropagation())};var Qa=u("ytEventsEventsListeners")||{};t("ytEventsEventsListeners",Qa,void 0);var we=u("ytEventsEventsCounter")||{count:0};t("ytEventsEventsCounter",we,void 0);function xe(a,b,c,d){d=void 0===d?!1:d;a.addEventListener&&("mouseenter"!=b||"onmouseenter"in document?"mouseleave"!=b||"onmouseenter"in document?"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"):b="mouseout":b="mouseover");return Pa(function(e){return!!e.length&&e[0]==a&&e[1]==b&&e[2]==c&&e[4]==!!d})}
function ye(a,b,c){var d=void 0===d?!1:d;if(!a||!a.addEventListener&&!a.attachEvent)return"";var e=xe(a,b,c,d);if(e)return e;e=++we.count+"";var f=!("mouseenter"!=b&&"mouseleave"!=b||!a.addEventListener||"onmouseenter"in document);var g=f?function(d){d=new ve(d);if(!Ab(d.relatedTarget,function(b){return b==a}))return d.currentTarget=a,d.type=b,c.call(a,d)}:function(b){b=new ve(b);
b.currentTarget=a;return c.call(a,b)};
g=kd(g);a.addEventListener?("mouseenter"==b&&f?b="mouseover":"mouseleave"==b&&f?b="mouseout":"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"),a.addEventListener(b,g,d)):a.attachEvent("on"+b,g);Qa[e]=[a,b,c,g,d];return e}
function ze(a){a&&("string"==typeof a&&(a=[a]),C(a,function(a){if(a in Qa){var b=Qa[a],d=b[0],e=b[1],f=b[3];b=b[4];d.removeEventListener?d.removeEventListener(e,f,b):d.detachEvent&&d.detachEvent("on"+e,f);delete Qa[a]}}))}
;function Ae(){if(null==u("_lact",window)){var a=parseInt(Q("LACT"),10);a=isFinite(a)?y()-Math.max(a,0):-1;t("_lact",a,window);t("_fact",a,window);-1==a&&V();ye(document,"keydown",V);ye(document,"keyup",V);ye(document,"mousedown",V);ye(document,"mouseup",V);vd("page-mouse",V);vd("page-scroll",V);vd("page-resize",V)}}
function V(){null==u("_lact",window)&&Ae();var a=y();t("_lact",a,window);-1==u("_fact",window)&&t("_fact",a,window);(a=u("ytglobal.ytUtilActivityCallback_"))&&a()}
function Be(){var a=u("_lact",window);return null==a?-1:Math.max(y()-a,0)}
;function Ce(a,b,c,d,e){this.f=a;this.i=b;this.h=c;this.g=d;this.b=e}
var De=1;function Ee(a){var b={};void 0!==a.f?b.trackingParams=a.f:(b.veType=a.i,null!=a.h&&(b.veCounter=a.h),null!=a.g&&(b.elementIndex=a.g));void 0!==a.b&&(b.dataElement=Ee(a.b));return b}
;var Fe={log_event:"events",log_event2:"events",log_interaction:"interactions"},Ge=Object.create(null);Ge.log_event="GENERIC_EVENT_LOGGING";Ge.log_event2="GENERIC_EVENT_LOGGING";Ge.log_interaction="INTERACTION_LOGGING";var He={},Ie={},Je=0,W=u("ytLoggingTransportLogPayloadsQueue_")||{};t("ytLoggingTransportLogPayloadsQueue_",W,void 0);var Ke=u("ytLoggingTransportTokensToCttTargetIds_")||{};t("ytLoggingTransportTokensToCttTargetIds_",Ke,void 0);var Le=u("ytLoggingTransportDispatchedStats_")||{};
t("ytLoggingTransportDispatchedStats_",Le,void 0);t("ytytLoggingTransportCapturedTime_",u("ytLoggingTransportCapturedTime_")||{},void 0);function Me(a,b){Ie[a.endpoint]=b;if(a.Y){var c=a.Y;var d={};c.videoId?d.videoId=c.videoId:c.playlistId&&(d.playlistId=c.playlistId);Ke[a.Y.token]=d;c=Ne(a.endpoint,a.Y.token)}else c=Ne(a.endpoint);c.push(a.payload);c.length>=(Number(T("web_logging_max_batch")||0)||20)?Oe():Pe()}
function Oe(){window.clearTimeout(Je);if(!Ra(W)){for(var a in W){var b=He[a];if(!b){var c=Ie[a];if(!c)continue;b=new c;He[a]=b}c=void 0;var d=a,e=b,f=Fe[d],g=Le[d]||{};Le[d]=g;b=Math.round(O());for(c in W[d]){var h=e.b;h={client:{hl:h.Fa,gl:h.Ea,clientName:h.Da,clientVersion:h.innertubeContextClientVersion}};Q("DELEGATED_SESSION_ID")&&(h.user={onBehalfOfUser:Q("DELEGATED_SESSION_ID")});h={context:h};h[f]=Ne(d,c);g.dispatchedEventCount=g.dispatchedEventCount||0;g.dispatchedEventCount+=h[f].length;
h.requestTimeMs=b;var l=Ke[c];if(l)a:{var m=h,w=c;if(l.videoId)var F="VIDEO";else if(l.playlistId)F="PLAYLIST";else break a;m.credentialTransferTokenTargetId=l;m.context=m.context||{};m.context.user=m.context.user||{};m.context.user.credentialTransferTokens=[{token:w,scope:F}]}delete Ke[c];Qe(e,d,h)}c=g;d=b;c.previousDispatchMs&&(b=d-c.previousDispatchMs,e=c.diffCount||0,c.averageTimeBetweenDispatchesMs=e?(c.averageTimeBetweenDispatchesMs*e+b)/(e+1):b,c.diffCount=e+1);c.previousDispatchMs=d;delete W[a]}Ra(W)||
Pe()}}
function Pe(){window.clearTimeout(Je);Je=U(Oe,Q("LOGGING_BATCH_TIMEOUT",1E4))}
function Ne(a,b){b||(b="");W[a]=W[a]||{};W[a][b]=W[a][b]||[];return W[a][b]}
;function Re(a,b,c,d,e){var f={};f.eventTimeMs=Math.round(d||O());f[a]=b;f.context={lastActivityMs:String(d?-1:Be())};Me({endpoint:"log_event",payload:f,Y:e},c)}
;function Se(a,b,c){Te(Ue,{attachChild:{csn:a,parentVisualElement:Ee(b),visualElements:[Ee(c)]}})}
function Te(a,b,c){b.eventTimeMs=c?c:Math.round(O());b.lactMs=Be();Me({endpoint:"log_interaction",payload:b},a)}
;function Ve(){if(!We&&!Xe||!window.JSON)return null;try{var a=We.get("yt-player-two-stage-token")}catch(b){}if(!r(a))try{a=Xe.get("yt-player-two-stage-token")}catch(b){}if(!r(a))return null;try{a=JSON.parse(a,void 0)}catch(b){}return a}
var Xe,Ye=new Wc;Xe=Ye.isAvailable()?new Sc(Ye):null;var We,Ze=new Xc;We=Ze.isAvailable()?new Sc(Ze):null;function $e(){var a=Q("ROOT_VE_TYPE",void 0);return a?new Ce(void 0,a,void 0):null}
function af(){var a=Q("client-screen-nonce")||Q("EVENT_ID");return a?a:null}
;function bf(a,b,c){Lb.set(""+a,b,c,"/","youtube.com",!1)}
;function cf(a){if(a){a=a.itct||a.ved;var b=u("yt.logging.screen.storeParentElement");a&&b&&b(new Ce(a))}}
;function df(a,b,c){b=void 0===b?{}:b;c=void 0===c?!1:c;var d=Q("EVENT_ID");d&&(b.ei||(b.ei=d));if(b){d=a;var e=Q("VALID_SESSION_TEMPDATA_DOMAINS",[]),f=Zc(N(window.location.href)[3]||null);f&&e.push(f);f=Zc(N(d)[3]||null);if(0<=B(e,f)||!f&&0==d.lastIndexOf("/",0))if(T("autoescape_tempdata_url")&&(e=document.createElement("a"),tb(e,d),d=e.href),d){f=N(d);d=f[5];e=f[6];f=f[7];var g="";d&&(g+=d);e&&(g+="?"+e);f&&(g+="#"+f);d=g;e=d.indexOf("#");if(d=0>e?d:d.substr(0,e)){if(b.itct||b.ved)b.csn=b.csn||
af();if(h){var h=parseInt(h,10);isFinite(h)&&0<h&&(d="ST-"+Da(d).toString(36),e=b?ad(b):"",bf(d,e,h||5),cf(b))}else h="ST-"+Da(d).toString(36),d=b?ad(b):"",bf(h,d,5),cf(b)}}}if(c)return!1;if((window.ytspf||{}).enabled)spf.navigate(a);else{var l=void 0===l?{}:l;var m=void 0===m?"":m;var w=void 0===w?window:w;c=w.location;a=bd(a,l)+m;a=a instanceof H?a:pb(a);c.href=nb(a)}return!0}
;t("yt.abuse.botguardInitialized",u("yt.abuse.botguardInitialized")||Nd,void 0);t("yt.abuse.invokeBotguard",u("yt.abuse.invokeBotguard")||Od,void 0);t("yt.abuse.dclkstatus.checkDclkStatus",u("yt.abuse.dclkstatus.checkDclkStatus")||se,void 0);t("yt.player.exports.navigate",u("yt.player.exports.navigate")||df,void 0);t("yt.util.activity.init",u("yt.util.activity.init")||Ae,void 0);t("yt.util.activity.getTimeSinceActive",u("yt.util.activity.getTimeSinceActive")||Be,void 0);
t("yt.util.activity.setTimestamp",u("yt.util.activity.setTimestamp")||V,void 0);function ef(a,b,c){c.context&&c.context.capabilities&&(c=c.context.capabilities,c.snapshot||c.golden)&&(a="vix");return"/youtubei/"+a+"/"+b}
;function Ue(a){this.b=a||{apiaryHost:R("APIARY_HOST"),eb:R("APIARY_HOST_FIRSTPARTY"),gapiHintOverride:!!Q("GAPI_HINT_OVERRIDE",void 0),gapiHintParams:R("GAPI_HINT_PARAMS"),innertubeApiKey:R("INNERTUBE_API_KEY"),innertubeApiVersion:R("INNERTUBE_API_VERSION"),Da:Q("INNERTUBE_CONTEXT_CLIENT_NAME","WEB"),innertubeContextClientVersion:R("INNERTUBE_CONTEXT_CLIENT_VERSION"),Fa:R("INNERTUBE_CONTEXT_HL"),Ea:R("INNERTUBE_CONTEXT_GL"),xhrApiaryHost:R("XHR_APIARY_HOST")||"",Ga:R("INNERTUBE_HOST_OVERRIDE")||""}}
function Qe(a,b,c){var d={};!Q("VISITOR_DATA")&&.01>Math.random()&&S(Error("Missing VISITOR_DATA when sending innertube request."),"WARNING");var e={headers:{"Content-Type":"application/json","X-Goog-Visitor-Id":Q("VISITOR_DATA","")},B:c,qa:"JSON",Z:d.Z,P:function(a,b){d.P&&d.P(b)},
onError:function(a,b){if(d.onError)d.onError(b)},
timeout:d.timeout,withCredentials:!0},f=Mb();f&&(e.headers.Authorization=f,e.headers["X-Goog-AuthUser"]=Q("SESSION_INDEX",0));var g="",h=a.b.Ga;h&&(g=h);f&&!g&&(e.headers["x-origin"]=window.location.origin);de(""+g+ef(a.b.innertubeApiVersion,b,c)+"?alt=json&key="+a.b.innertubeApiKey,e)}
;function ff(a){a=a||{};this.url=a.url||"";this.args=a.args||Ta(gf);this.assets=a.assets||{};this.attrs=a.attrs||Ta(hf);this.params=a.params||Ta(jf);this.minVersion=a.min_version||"8.0.0";this.fallback=a.fallback||null;this.fallbackMessage=a.fallbackMessage||null;this.html5=!!a.html5;this.disable=a.disable||{};this.loaded=!!a.loaded;this.messages=a.messages||{}}
var gf={enablejsapi:1},hf={},jf={allowscriptaccess:"always",allowfullscreen:"true",bgcolor:"#000000"};function kf(a){a instanceof ff||(a=new ff(a));return a}
function lf(a){var b=new ff,c;for(c in a)if(a.hasOwnProperty(c)){var d=a[c];b[c]="object"==ra(d)?Ta(d):d}return b}
;function mf(a){J.call(this);this.b=[];this.f=a||this}
n(mf,J);function nf(a,b,c,d){d=kd(v(d,a.f));d={target:b,name:c,ma:d};b.addEventListener(c,d.ma,void 0);a.b.push(d)}
function of(a){for(;a.b.length;){var b=a.b.pop();b.target.removeEventListener(b.name,b.ma)}}
mf.prototype.l=function(){of(this);J.prototype.l.call(this)};function pf(){this.b=this.minor=this.major=0;var a=u("window.navigator.plugins"),b=u("window.navigator.mimeTypes");a=a&&a["Shockwave Flash"];b=b&&b["application/x-shockwave-flash"];if(b=a&&b&&b.enabledPlugin&&a.description||""){a=b.indexOf("Shockwave Flash");0<=a&&(b=b.substr(a+15));a=b.split(" ");var c="";b="";for(var d=0,e=a.length;d<e;d++)if(c)if(b)break;else b=a[d];else c=a[d];c=c.split(".");a=parseInt(c[0],10)||0;c=parseInt(c[1],10)||0;d=0;if("r"==b.charAt(0)||"d"==b.charAt(0))d=parseInt(b.substr(1),
10)||0;b=[a,c,d]}else b=[0,0,0];this.major=b[0];this.minor=b[1];this.b=b[2];if(0>=this.major){if(id)try{var f=new ActiveXObject("ShockwaveFlash.ShockwaveFlash")}catch(m){f=null}else{var g=document.body;var h=document.createElement("object");h.setAttribute("type","application/x-shockwave-flash");f=g.appendChild(h)}if(f&&"GetVariable"in f)try{var l=f.GetVariable("$version")}catch(m){l=""}g&&h&&g.removeChild(h);(f=l||"")?(f=f.split(" ")[1].split(","),f=[parseInt(f[0],10)||0,parseInt(f[1],10)||0,parseInt(f[2],
10)||0]):f=[0,0,0];this.major=f[0];this.minor=f[1];this.b=f[2]}}
qa(pf);var qf=/cssbin\/(?:debug-)?([a-zA-Z0-9_-]+?)(?:-2x|-web|-rtl|-vfl|.css)/;function rf(a){a=a||"";if(window.spf){var b=a.match(qf);spf.style.load(a,b?b[1]:"",void 0)}else sf(a)}
function sf(a){var b=tf(a),c=document.getElementById(b),d=c&&nd(c,"loaded");d||c&&!d||(c=uf(a,b,function(){nd(c,"loaded")||(ld(c),yd(b),U(x(zd,b),0))}))}
function uf(a,b,c){var d=document.createElement("link");d.id=b;d.onload=function(){c&&setTimeout(c,0)};
a=Bb(a);d.rel="stylesheet";d.href=lb(a);(document.getElementsByTagName("head")[0]||document.body).appendChild(d);return d}
function tf(a){var b=document.createElement("A");a=qb(a);tb(b,a);b=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"css-"+Da(b)}
;var X={},vf=(X["api.invalidparam"]=2,X.auth=150,X["drm.auth"]=150,X["heartbeat.net"]=150,X["heartbeat.servererror"]=150,X["heartbeat.stop"]=150,X["html5.unsupportedads"]=5,X["fmt.noneavailable"]=5,X["fmt.decode"]=5,X["fmt.unplayable"]=5,X["html5.missingapi"]=5,X["html5.unsupportedlive"]=5,X["drm.unavailable"]=5,X);var wf={cupcake:1.5,donut:1.6,eclair:2,froyo:2.2,gingerbread:2.3,honeycomb:3,"ice cream sandwich":4,jellybean:4.1,kitkat:4.4,lollipop:5.1,marshmallow:6,nougat:7.1},xf;var yf=Ka;yf=yf.toLowerCase();if(-1!=yf.indexOf("android")){var zf=yf.match(/android\D*(\d\.\d)[^\;|\)]*[\;\)]/);if(zf)xf=parseFloat(zf[1]);else{var Af=[],Bf=0,Cf;for(Cf in wf)Af[Bf++]=Cf;var Df=yf.match("("+Af.join("|")+")");xf=Df?wf[Df[0]]:0}}else xf=void 0;var Ef=['video/mp4; codecs="avc1.42001E, mp4a.40.2"','video/webm; codecs="vp8.0, vorbis"'],Ff=['audio/mp4; codecs="mp4a.40.2"'];var Gf=u("ytLoggingLatencyUsageStats_")||{};t("ytLoggingLatencyUsageStats_",Gf,void 0);var Hf=0;function If(a){Gf[a]=Gf[a]||{count:0};var b=Gf[a];b.count++;b.time=O();Hf||(Hf=ne(Jf,0));return 10<b.count?(11==b.count&&ke(Error("CSI data exceeded logging limit with key: "+a),0==a.indexOf("info")?"WARNING":"ERROR"),!0):!1}
function Jf(){var a=O(),b;for(b in Gf)6E4<a-Gf[b].time&&delete Gf[b];Hf=0}
;function Kf(a,b){this.version=a;this.args=b}
;function Lf(a){this.topic=a}
Lf.prototype.toString=function(){return this.topic};var Mf=u("ytPubsub2Pubsub2Instance")||new L;L.prototype.subscribe=L.prototype.subscribe;L.prototype.unsubscribeByKey=L.prototype.D;L.prototype.publish=L.prototype.K;L.prototype.clear=L.prototype.clear;t("ytPubsub2Pubsub2Instance",Mf,void 0);t("ytPubsub2Pubsub2SubscribedKeys",u("ytPubsub2Pubsub2SubscribedKeys")||{},void 0);t("ytPubsub2Pubsub2TopicToKeys",u("ytPubsub2Pubsub2TopicToKeys")||{},void 0);t("ytPubsub2Pubsub2IsAsync",u("ytPubsub2Pubsub2IsAsync")||{},void 0);
t("ytPubsub2Pubsub2SkipSubKey",null,void 0);function Nf(a,b){var c=u("ytPubsub2Pubsub2Instance");c&&c.publish.call(c,a.toString(),a,b)}
;function Of(){var a=Q("TIMING_TICK_EXPIRATION");a||(a={},P("TIMING_TICK_EXPIRATION",a));return a}
function Pf(){var a=Of(),b;for(b in a)oe(a[b]);P("TIMING_TICK_EXPIRATION",{})}
;function Qf(a,b){Kf.call(this,1,arguments)}
n(Qf,Kf);function Rf(a,b){Kf.call(this,1,arguments)}
n(Rf,Kf);var Sf=new Lf("aft-recorded"),Tf=new Lf("timing-sent");var Y=window.performance||window.mozPerformance||window.msPerformance||window.webkitPerformance||{};var Uf=y().toString();var Vf={vc:!0},Wf={ad_allowed:"adTypesAllowed",ad_at:"adType",ad_cpn:"adClientPlaybackNonce",ad_docid:"adVideoId",yt_ad_an:"adNetworks",p:"httpProtocol",t:"transportProtocol",cpn:"clientPlaybackNonce",csn:"clientScreenNonce",docid:"videoId",is_nav:"isNavigation",yt_lt:"loadType",yt_ad:"isMonetized",nr:"webInfo.navigationReason",ncnp:"webInfo.nonPreloadedNodeCount",plid:"videoId",paused:"playerInfo.isPausedOnLoad",fmt:"playerInfo.itag",yt_pl:"watchInfo.isPlaylist",yt_ad_pr:"prerollAllowed",yt_red:"isRedSubscriber",
st:"serverTimeMs",vph:"viewportHeight",vpw:"viewportWidth",yt_vis:"isVisible"},Xf="ap c cver ei srt yt_fss yt_li ba vpil vpni yt_eil pa GetBrowse_rid GetPlayer_rid GetSearch_rid GetWatchNext_rid cmt pc prerender psc rc start yt_abt yt_fn yt_fs yt_pft yt_pre yt_pt yt_pvis yt_ref yt_sts".split(" "),Yf="isNavigation isMonetized playerInfo.isPausedOnLoad prerollAllowed isRedSubscriber isVisible watchInfo.isPlaylist".split(" "),Zf=!1;
function $f(a){if("_"!=a[0]){var b=a;Y.mark&&(0==b.lastIndexOf("mark_",0)||(b="mark_"+b),Y.mark(b))}b=ag();var c=O();b[a]&&(b["_"+a]=b["_"+a]||[b[a]],b["_"+a].push(c));b[a]=c;b=Of();if(c=b[a])oe(c),b[a]=0;bg()["tick_"+a]=void 0;O();T("csi_on_gel")?(b=cg(),"_start"==a?If("baseline_"+b)||Re("latencyActionBaselined",{clientActionNonce:b},Ue,void 0,void 0):If("tick_"+a+"_"+b)||Re("latencyActionTicked",{tickName:a,clientActionNonce:b},Ue,void 0,void 0),a=!0):a=!1;if(a=!a)a=!u("yt.timing.pingSent_");if(a&&
(b=R("TIMING_ACTION"),a=ag(),u("ytglobal.timingready_")&&b&&a._start&&(b=dg()))){T("tighter_critical_section")&&!Zf&&(Nf(Sf,new Qf(Math.round(b-a._start),void 0)),Zf=!0);b=!0;c=Q("TIMING_WAIT",[]);if(c.length)for(var d=0,e=c.length;d<e;++d)if(!(c[d]in a)){b=!1;break}b&&eg()}}
function fg(){var a=gg().info.yt_lt="hot_bg";bg().info_yt_lt=a;if(T("csi_on_gel"))if("yt_lt"in Wf){var b={},c=Wf.yt_lt;0<=B(Yf,c)&&(a=!!a);c=c.split(".");for(var d=b,e=0;e<c.length-1;e++)d[c[e]]=d[c[e]]||{},d=d[c[e]];b[c[c.length-1]]=a;a=cg();c=Object.keys(b).join("");If("info_"+c+"_"+a)||(b.clientActionNonce=a,Re("latencyActionInfo",b,Ue,void 0,void 0))}else 0<=B(Xf,"yt_lt")||S(Error("Unknown label yt_lt logged with GEL CSI."))}
function dg(){var a=ag();if(a.aft)return a.aft;for(var b=Q("TIMING_AFT_KEYS",["ol"]),c=b.length,d=0;d<c;d++){var e=a[b[d]];if(e)return e}return NaN}
function eg(){Pf();if(!T("csi_on_gel")){var a=ag(),b=gg().info,c=a._start,d;for(d in a)if(0==d.lastIndexOf("_",0)&&sa(a[d])){var e=d.slice(1);if(e in Vf){var f=Fa(a[d],function(a){return Math.round(a-c)});
b["all_"+e]=f.join()}delete a[d]}e=!!b.ap;if(f=u("ytglobal.timingReportbuilder_")){if(f=f(a,b,void 0))hg(f,e),ig(),jg(),kg(!1,void 0),Q("TIMING_ACTION")&&P("PREVIOUS_ACTION",Q("TIMING_ACTION")),P("TIMING_ACTION","")}else{var g=Q("CSI_SERVICE_NAME","youtube");f={v:2,s:g,action:Q("TIMING_ACTION",void 0)};var h=b.srt;void 0!==a.srt&&delete b.srt;if(b.h5jse){var l=window.location.protocol+u("ytplayer.config.assets.js");(l=Y.getEntriesByName?Y.getEntriesByName(l)[0]:null)?b.h5jse=Math.round(b.h5jse-l.responseEnd):
delete b.h5jse}a.aft=dg();lg()&&"youtube"==g&&(fg(),g=a.vc,l=a.pbs,delete a.aft,b.aft=Math.round(l-g));for(var m in b)"_"!=m.charAt(0)&&(f[m]=b[m]);a.ps=O();b={};m=[];for(d in a)"_"!=d.charAt(0)&&(g=Math.round(a[d]-c),b[d]=g,m.push(d+"."+g));f.rt=m.join(",");(a=u("ytdebug.logTiming"))&&a(f,b);hg(f,e,void 0);Nf(Tf,new Rf(b.aft+(h||0),void 0))}}}
var jg=v(Y.clearResourceTimings||Y.webkitClearResourceTimings||Y.mozClearResourceTimings||Y.msClearResourceTimings||Y.oClearResourceTimings||pa,Y);
function hg(a,b,c){if(T("debug_csi_data")){var d=u("yt.timing.csiData");d||(d=[],t("yt.timing.csiData",d,void 0));d.push({page:location.href,time:new Date,args:a})}d="";for(var e in a)d+="&"+e+"="+a[e];a="/csi_204?"+d.substring(1);if(window.navigator&&window.navigator.sendBeacon&&b)try{window.navigator&&window.navigator.sendBeacon&&window.navigator.sendBeacon(a,"")||ge(a,void 0)}catch(f){ge(a,void 0)}else ge(a);kg(!0,c)}
function cg(){var a=gg().nonce;if(!a){a:{if(window.crypto&&window.crypto.getRandomValues)try{var b=Array(16),c=new Uint8Array(16);window.crypto.getRandomValues(c);for(a=0;a<b.length;a++)b[a]=c[a];var d=b;break a}catch(e){}d=Array(16);for(b=0;16>b;b++){c=y();for(a=0;a<c%23;a++)d[b]=Math.random();d[b]=Math.floor(256*Math.random())}if(Uf)for(b=1,c=0;c<Uf.length;c++)d[b%16]=d[b%16]^d[(b-1)%16]/4^Uf.charCodeAt(c),b++}b=[];for(c=0;c<d.length;c++)b.push("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_".charAt(d[c]&
63));a=b.join("");gg().nonce=a}return a}
function ag(){return gg().tick}
function bg(){var a=gg();"gel"in a||(a.gel={});return a.gel}
function gg(){return u("ytcsi.data_")||ig()}
function ig(){var a={tick:{},info:{}};t("ytcsi.data_",a,void 0);return a}
function kg(a,b){t("yt.timing."+(b||"")+"pingSent_",a,void 0)}
function lg(){var a=ag(),b=a.pbr,c=a.vc;a=a.pbs;return b&&c&&a&&b<c&&c<a&&1==gg().info.yt_pvis}
;function mg(a,b){J.call(this);this.o=this.j=a;this.O=b;this.A=!1;this.f={};this.U=this.N=null;this.J=new L;cc(this,x(dc,this.J));this.i={};this.G=this.V=this.h=this.da=this.b=null;this.R=!1;this.H=this.w=this.m=this.M=null;this.W={};this.ua=["onReady"];this.S=new mf(this);cc(this,x(dc,this.S));this.ba=null;this.ka=NaN;this.T={};ng(this);this.C("onDetailedError",v(this.La,this));this.C("onTabOrderChange",v(this.wa,this));this.C("onTabAnnounce",v(this.la,this));this.C("WATCH_LATER_VIDEO_ADDED",v(this.Ma,
this));this.C("WATCH_LATER_VIDEO_REMOVED",v(this.Na,this));ac||(this.C("onMouseWheelCapture",v(this.Ja,this)),this.C("onMouseWheelRelease",v(this.Ka,this)));this.C("onAdAnnounce",v(this.la,this));this.I=new mf(this);cc(this,x(dc,this.I));this.ca=!1;this.aa=null}
n(mg,J);k=mg.prototype;k.ja=function(a,b){this.g||(og(this,a),pg(this,b),this.A&&qg(this))};
function og(a,b){a.da=b;a.b=lf(b);a.h=a.b.attrs.id||a.h;"video-player"==a.h&&(a.h=a.O,a.b.attrs.id=a.O);a.o.id==a.h&&(a.h+="-player",a.b.attrs.id=a.h);a.b.args.enablejsapi="1";a.b.args.playerapiid=a.O;a.V||(a.V=rg(a,a.b.args.jsapicallback||"onYouTubePlayerReady"));a.b.args.jsapicallback=null;var c=a.b.attrs.width;c&&(a.o.style.width=Eb(Number(c)||c));if(c=a.b.attrs.height)a.o.style.height=Eb(Number(c)||c)}
k.za=function(){return this.da};
function qg(a){a.b.loaded||(a.b.loaded=!0,"0"!=a.b.args.autoplay?a.f.loadVideoByPlayerVars(a.b.args):a.f.cueVideoByPlayerVars(a.b.args))}
function sg(a){var b=a.b&&a.b.args;if(b&&b.fflags){var c=b.el;b=b.fflags;if(!c||"profilepage"==c||"embedded"==c&&0<=b.indexOf("web_player_disable_flash_embed=true")||0<=b.indexOf("web_player_disable_flash_playerproxy=true"))return!1}if(!q(a.b.disable.flash)){c=a.b.disable;b=pf.getInstance();var d=a.b.minVersion;d="string"==typeof d?d.split("."):[d,void 0,void 0];d[0]=parseInt(d[0],10)||0;d[1]=parseInt(d[1],10)||0;d[2]=parseInt(d[2],10)||0;c.flash=!(b.major>d[0]||b.major==d[0]&&b.minor>d[1]||b.major==
d[0]&&b.minor==d[1]&&b.b>=d[2])}return!a.b.disable.flash}
function tg(a,b){var c=a.b,d=c&&c.args&&c.args.fflags;!d||0>d.indexOf("web_player_flash_fallback_killswitch=true")||b&&(5!=(vf[b.errorCode]||5)||-1==ug.indexOf(b.errorCode))||!sg(a)||((d=vg(a))&&d.stopVideo&&d.stopVideo(),d&&d.getUpdatedConfigurationData&&(c=d.getUpdatedConfigurationData(),c=kf(c)),c.args.autoplay=1,c.args.html5_unavailable="1",og(a,c),pg(a,"flash"))}
function pg(a,b){if(!a.g){if(!b){var c;if(!(c=!a.b.html5&&sg(a))){if(!q(a.b.disable.html5)){c=!0;void 0!=a.b.args.deviceHasDisplay&&(c=a.b.args.deviceHasDisplay);if(2.2==xf)var d=!0;else{a:{var e=c;c=u("yt.player.utils.videoElement_");c||(c=document.createElement("VIDEO"),t("yt.player.utils.videoElement_",c,void 0));try{if(c.canPlayType){e=e?Ef:Ff;for(var f=0;f<e.length;f++)if(c.canPlayType(e[f])){d=null;break a}}d="fmt.noneavailable"}catch(g){d="html5.missingapi"}}d=!d}d&&(d=wg(a)||a.b.assets.js);
a.b.disable.html5=!d;d||(a.b.args.html5_unavailable="1")}c=!!a.b.disable.html5}b=c?sg(a)?"flash":"unsupported":"html5"}("flash"==b?a.bb:a.cb).call(a)}}
function wg(a){var b=!0,c=vg(a);c&&a.b&&(a=a.b,b=nd(c,"version")==a.assets.js);return b&&!!u("yt.player.Application.create")}
k.cb=function(){if(!this.R){var a=wg(this);if(a&&"html5"==xg(this))this.G="html5",this.A||this.L();else if(yg(this),this.G="html5",a&&this.m)this.j.appendChild(this.m),this.L();else{this.b.loaded=!0;var b=!1;this.M=v(function(){b=!0;var a=lf(this.b);u("yt.player.Application.create")(this.j,a);this.L()},this);
this.R=!0;a?this.M():(Dd(this.b.assets.js,this.M),rf(this.b.assets.css),zg(this)&&!b&&t("yt.player.Application.create",null,void 0))}}};
k.bb=function(){var a=lf(this.b);if(!this.w){var b=vg(this);b&&(this.w=document.createElement("SPAN"),this.w.tabIndex=0,nf(this.S,this.w,"focus",this.oa),this.H=document.createElement("SPAN"),this.H.tabIndex=0,nf(this.S,this.H,"focus",this.oa),b.parentNode&&b.parentNode.insertBefore(this.w,b),b.parentNode&&b.parentNode.insertBefore(this.H,b.nextSibling))}a.attrs.width=a.attrs.width||"100%";a.attrs.height=a.attrs.height||"100%";if("flash"==xg(this))this.G="flash",this.A||this.L();else{yg(this);this.G=
"flash";this.b.loaded=!0;window!=window.top&&document.referrer&&(a.args.framer=document.referrer.substring(0,128));b=this.j;var c=a.url;if(c){b=r(b)?xb(b):b;var d=Ta(a.attrs);d.tabindex=0;var e=Ta(a.params);e.flashvars=ad(a.args);if(id){d.classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000";e.movie=c;a=document.createElement("object");for(var f in d)a.setAttribute(f,d[f]);for(var g in e)f=document.createElement("param"),f.setAttribute("name",g),f.setAttribute("value",e[g]),a.appendChild(f)}else{d.type=
"application/x-shockwave-flash";d.src=c;a=document.createElement("embed");a.setAttribute("name",d.id);for(var h in d)a.setAttribute(h,d[h]);for(var l in e)a.setAttribute(l,e[l])}g=document.createElement("div");g.appendChild(a);b.innerHTML=g.innerHTML}this.L()}};
k.oa=function(){vg(this).focus()};
function vg(a){var b=xb(a.h);!b&&a.o&&a.o.querySelector&&(b=a.o.querySelector("#"+a.h));return b}
k.L=function(){if(!this.g){var a=vg(this),b=!1;try{a&&a.getApiInterface&&a.getApiInterface()&&(b=!0)}catch(f){}if(b)if(this.R=!1,a.isNotServable&&a.isNotServable(this.b.args.video_id))tg(this);else{ng(this);this.A=!0;a=vg(this);a.addEventListener&&(this.N=Ag(this,a,"addEventListener"));a.removeEventListener&&(this.U=Ag(this,a,"removeEventListener"));b=a.getApiInterface();b=b.concat(a.getInternalApiInterface());for(var c=0;c<b.length;c++){var d=b[c];this.f[d]||(this.f[d]=Ag(this,a,d))}for(var e in this.i)this.N(e,
this.i[e]);qg(this);this.V&&this.V(this.f);this.J.K("onReady",this.f)}else this.ka=U(v(this.L,this),50)}};
function Ag(a,b,c){var d=b[c];return function(){try{return a.ba=null,d.apply(b,arguments)}catch(e){"Bad NPObject as private data!"!=e.message&&"sendAbandonmentPing"!=c&&(e.message+=" ("+c+")",a.ba=e,S(e,"WARNING"))}}}
function ng(a){a.A=!1;if(a.U)for(var b in a.i)a.U(b,a.i[b]);for(var c in a.T)window.clearTimeout(parseInt(c,10));a.T={};a.N=null;a.U=null;for(var d in a.f)a.f[d]=null;a.f.addEventListener=v(a.C,a);a.f.removeEventListener=v(a.Sa,a);a.f.destroy=v(a.dispose,a);a.f.getLastError=v(a.Aa,a);a.f.getPlayerType=v(a.Ba,a);a.f.getCurrentVideoConfig=v(a.za,a);a.f.loadNewVideoConfig=v(a.ja,a);a.f.isReady=v(a.Ha,a)}
k.Ha=function(){return this.A};
k.C=function(a,b){if(!this.g){var c=rg(this,b);if(c){if(!(0<=B(this.ua,a)||this.i[a])){var d=Bg(this,a);this.N&&this.N(a,d)}this.J.subscribe(a,c);"onReady"==a&&this.A&&U(x(c,this.f),0)}}};
k.Sa=function(a,b){if(!this.g){var c=rg(this,b);c&&Mc(this.J,a,c)}};
function rg(a,b){var c=b;if("string"==typeof b){if(a.W[b])return a.W[b];c=function(){var a=u(b);a&&a.apply(p,arguments)};
a.W[b]=c}return c?c:null}
function Bg(a,b){var c="ytPlayer"+b+a.O,d=v(function(a){if("html5"==xg(this)){var c=this.b&&this.b.args&&this.b.args.fflags;if(c&&0>c.indexOf("use_html5_player_event_timeout=true")){this.J.K(b,a);return}}var d=U(v(function(){if(!this.g){this.J.K(b,a);var c=this.T,e=String(d);e in c&&delete c[e]}},this),0);
Sa(this.T,String(d))},a);
a.i[b]=c;p[c]=d;return c}
k.wa=function(a){a=a?zb:yb;for(var b=a(document.activeElement);b&&(1!=b.nodeType||b==this.w||b==this.H||(b.focus(),b!=document.activeElement));)b=a(b)};
k.la=function(a){yd("a11y-announce",a)};
k.La=function(a){tg(this,a)};
k.Ma=function(a){yd("WATCH_LATER_VIDEO_ADDED",a)};
k.Na=function(a){yd("WATCH_LATER_VIDEO_REMOVED",a)};
k.Ja=function(){if(!this.ca){if(bc){var a=document,b=a.scrollingElement?a.scrollingElement:ab||"CSS1Compat"!=a.compatMode?a.body||a.documentElement:a.documentElement;a=a.parentWindow||a.defaultView;this.aa=E&&G("10")&&a.pageYOffset!=b.scrollTop?new vb(b.scrollLeft,b.scrollTop):new vb(a.pageXOffset||b.scrollLeft,a.pageYOffset||b.scrollTop);nf(this.I,window,"scroll",this.Qa);nf(this.I,this.j,"touchmove",this.Pa)}else nf(this.I,this.j,"mousewheel",this.pa),nf(this.I,this.j,"wheel",this.pa);this.ca=!0}};
k.Ka=function(){of(this.I);this.ca=!1};
k.pa=function(a){a=a||window.event;a.returnValue=!1;a.preventDefault&&a.preventDefault()};
k.Qa=function(){window.scrollTo(this.aa.x,this.aa.y)};
k.Pa=function(a){a.preventDefault()};
k.Ba=function(){return this.G||xg(this)};
k.Aa=function(){return this.ba};
function xg(a){return(a=vg(a))?"div"==a.tagName.toLowerCase()?"html5":"flash":null}
function yg(a){$f("dcp");a.cancel();ng(a);a.G=null;a.b&&(a.b.loaded=!1);var b=vg(a);"html5"==xg(a)?wg(a)||!zg(a)?a.m=b:(b&&b.destroy&&b.destroy(),a.m=null):b&&b.destroy&&b.destroy();b=a.j;for(var c;c=b.firstChild;)b.removeChild(c);of(a.S);a.w=null;a.H=null}
k.cancel=function(){this.M&&Jd(this.b.assets.js,this.M);window.clearTimeout(this.ka);this.R=!1};
k.l=function(){yg(this);if(this.m&&this.b&&this.m.destroy)try{this.m.destroy()}catch(b){S(b)}this.W=null;for(var a in this.i)p[this.i[a]]=null;this.da=this.b=this.f=null;delete this.j;delete this.o;J.prototype.l.call(this)};
function zg(a){return a.b&&a.b.args&&a.b.args.fflags?-1!=a.b.args.fflags.indexOf("player_destroy_old_version=true"):!1}
var ug=["fmt.noneavailable","html5.missingapi","html5.unsupportedads","html5.unsupportedlive"];var Cg={},Dg="player_uid_"+(1E9*Math.random()>>>0);function Eg(a){var b="player";b=r(b)?xb(b):b;a=kf(a);var c=Dg+"_"+(b[xa]||(b[xa]=++ya)),d=Cg[c];if(d)return d.ja(a),d.f;d=new mg(b,c);Cg[c]=d;yd("player-added",d.f);cc(d,x(Fg,d));U(function(){d.ja(a)},0);
return d.f}
function Fg(a){delete Cg[a.O]}
;function Gg(a){return(0==a.search("cue")||0==a.search("load"))&&"loadModule"!=a}
function Hg(a,b,c){r(a)&&(a={mediaContentUrl:a,startSeconds:b,suggestedQuality:c});b=/\/([ve]|embed)\/([^#?]+)/.exec(a.mediaContentUrl);a.videoId=b&&b[2]?b[2]:null;return Ig(a)}
function Ig(a,b,c){if(va(a)){b="endSeconds startSeconds mediaContentUrl suggestedQuality videoId two_stage_token".split(" ");c={};for(var d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}return{videoId:a,startSeconds:b,suggestedQuality:c}}
function Jg(a,b,c,d){if(va(a)&&!sa(a)){b="playlist list listType index startSeconds suggestedQuality".split(" ");c={};for(d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}b={index:b,startSeconds:c,suggestedQuality:d};r(a)&&16==a.length?b.list="PL"+a:b.playlist=a;return b}
function Kg(a){var b=a.video_id||a.videoId;if(r(b)){var c=Ve()||{},d=Ve()||{};q(void 0)?d[b]=void 0:delete d[b];var e=y()+3E5,f=Xe;if(f&&window.JSON){r(d)||(d=JSON.stringify(d,void 0));try{f.set("yt-player-two-stage-token",d,e)}catch(g){f.remove("yt-player-two-stage-token")}}(b=c[b])&&(a.two_stage_token=b)}}
;function Lg(a){J.call(this);this.f=a;this.f.subscribe("command",this.ra,this);this.h={};this.i=!1}
z(Lg,J);k=Lg.prototype;k.start=function(){this.i||this.g||(this.i=!0,Mg(this.f,"RECEIVING"))};
k.ra=function(a,b){if(this.i&&!this.g){var c=b||{};switch(a){case "addEventListener":if(r(c.event)&&(c=c.event,!(c in this.h))){var d=v(this.Ua,this,c);this.h[c]=d;this.addEventListener(c,d)}break;case "removeEventListener":r(c.event)&&Ng(this,c.event);break;default:this.b.isReady()&&this.b[a]&&(c=Og(a,b||{}),c=this.b[a].apply(this.b,c),(c=Pg(a,c))&&this.i&&!this.g&&Mg(this.f,a,c))}}};
k.Ua=function(a,b){this.i&&!this.g&&Mg(this.f,a,this.ea(a,b))};
k.ea=function(a,b){if(null!=b)return{value:b}};
function Ng(a,b){b in a.h&&(a.removeEventListener(b,a.h[b]),delete a.h[b])}
k.l=function(){var a=this.f;a.g||Mc(a.b,"command",this.ra,this);this.f=null;for(var b in this.h)Ng(this,b);Lg.u.l.call(this)};function Qg(a,b){Lg.call(this,b);this.b=a;this.start()}
z(Qg,Lg);Qg.prototype.addEventListener=function(a,b){this.b.addEventListener(a,b)};
Qg.prototype.removeEventListener=function(a,b){this.b.removeEventListener(a,b)};
function Og(a,b){switch(a){case "loadVideoById":return b=Ig(b),Kg(b),[b];case "cueVideoById":return b=Ig(b),Kg(b),[b];case "loadVideoByPlayerVars":return Kg(b),[b];case "cueVideoByPlayerVars":return Kg(b),[b];case "loadPlaylist":return b=Jg(b),Kg(b),[b];case "cuePlaylist":return b=Jg(b),Kg(b),[b];case "seekTo":return[b.seconds,b.allowSeekAhead];case "playVideoAt":return[b.index];case "setVolume":return[b.volume];case "setPlaybackQuality":return[b.suggestedQuality];case "setPlaybackRate":return[b.suggestedRate];
case "setLoop":return[b.loopPlaylists];case "setShuffle":return[b.shufflePlaylist];case "getOptions":return[b.module];case "getOption":return[b.module,b.option];case "setOption":return[b.module,b.option,b.value];case "handleGlobalKeyDown":return[b.keyCode,b.shiftKey]}return[]}
function Pg(a,b){switch(a){case "isMuted":return{muted:b};case "getVolume":return{volume:b};case "getPlaybackRate":return{playbackRate:b};case "getAvailablePlaybackRates":return{availablePlaybackRates:b};case "getVideoLoadedFraction":return{videoLoadedFraction:b};case "getPlayerState":return{playerState:b};case "getCurrentTime":return{currentTime:b};case "getPlaybackQuality":return{playbackQuality:b};case "getAvailableQualityLevels":return{availableQualityLevels:b};case "getDuration":return{duration:b};
case "getVideoUrl":return{videoUrl:b};case "getVideoEmbedCode":return{videoEmbedCode:b};case "getPlaylist":return{playlist:b};case "getPlaylistIndex":return{playlistIndex:b};case "getOptions":return{options:b};case "getOption":return{option:b}}}
Qg.prototype.ea=function(a,b){switch(a){case "onReady":return;case "onStateChange":return{playerState:b};case "onPlaybackQualityChange":return{playbackQuality:b};case "onPlaybackRateChange":return{playbackRate:b};case "onError":return{errorCode:b}}return Qg.u.ea.call(this,a,b)};
Qg.prototype.l=function(){Qg.u.l.call(this);delete this.b};function Rg(a,b,c,d){J.call(this);this.f=b||null;this.o="*";this.h=c||null;this.sessionId=null;this.channel=d||null;this.A=!!a;this.m=v(this.w,this);window.addEventListener("message",this.m)}
n(Rg,J);Rg.prototype.w=function(a){if(!("*"!=this.h&&a.origin!=this.h||this.f&&a.source!=this.f)&&r(a.data)){try{var b=JSON.parse(a.data)}catch(c){return}if(!(null==b||this.A&&(this.sessionId&&this.sessionId!=b.id||this.channel&&this.channel!=b.channel))&&b)switch(b.event){case "listening":"null"!=a.origin&&(this.h=this.o=a.origin);this.f=a.source;this.sessionId=b.id;this.b&&(this.b(),this.b=null);break;case "command":this.i&&(!this.j||0<=B(this.j,b.func))&&this.i(b.func,b.args)}}};
Rg.prototype.sendMessage=function(a,b){var c=b||this.f;if(c){this.sessionId&&(a.id=this.sessionId);this.channel&&(a.channel=this.channel);try{var d=nc(a);c.postMessage(d,this.o)}catch(e){S(e,"WARNING")}}};
Rg.prototype.l=function(){window.removeEventListener("message",this.m);J.prototype.l.call(this)};function Sg(a,b,c){Rg.call(this,a,b,c||Q("POST_MESSAGE_ORIGIN",void 0)||window.document.location.protocol+"//"+window.document.location.hostname,"widget");this.j=this.b=this.i=null}
n(Sg,Rg);function Tg(){var a=this.g=new Sg(!!Q("WIDGET_ID_ENFORCE")),b=v(this.Ra,this);a.i=b;a.j=null;this.g.channel="widget";if(a=Q("WIDGET_ID"))this.g.sessionId=a;this.h=[];this.j=!1;this.i={}}
k=Tg.prototype;k.Ra=function(a,b){if("addEventListener"==a&&b){var c=b[0];this.i[c]||"onReady"==c||(this.addEventListener(c,Ug(this,c)),this.i[c]=!0)}else this.ta(a,b)};
k.ta=function(){};
function Ug(a,b){return v(function(a){this.sendMessage(b,a)},a)}
k.addEventListener=function(){};
k.ya=function(){this.j=!0;this.sendMessage("initialDelivery",this.fa());this.sendMessage("onReady");C(this.h,this.sa,this);this.h=[]};
k.fa=function(){return null};
function Vg(a,b){a.sendMessage("infoDelivery",b)}
k.sa=function(a){this.j?this.g.sendMessage(a):this.h.push(a)};
k.sendMessage=function(a,b){this.sa({event:a,info:void 0==b?null:b})};
k.dispose=function(){this.g=null};function Wg(a){Tg.call(this);this.b=a;this.f=[];this.addEventListener("onReady",v(this.Oa,this));this.addEventListener("onVideoProgress",v(this.Ya,this));this.addEventListener("onVolumeChange",v(this.Za,this));this.addEventListener("onApiChange",v(this.Ta,this));this.addEventListener("onPlaybackQualityChange",v(this.Va,this));this.addEventListener("onPlaybackRateChange",v(this.Wa,this));this.addEventListener("onStateChange",v(this.Xa,this))}
z(Wg,Tg);k=Wg.prototype;k.ta=function(a,b){if(this.b[a]){b=b||[];if(0<b.length&&Gg(a)){var c=b;if(va(c[0])&&!sa(c[0]))c=c[0];else{var d={};switch(a){case "loadVideoById":case "cueVideoById":d=Ig.apply(window,c);break;case "loadVideoByUrl":case "cueVideoByUrl":d=Hg.apply(window,c);break;case "loadPlaylist":case "cuePlaylist":d=Jg.apply(window,c)}c=d}Kg(c);b.length=1;b[0]=c}this.b[a].apply(this.b,b);Gg(a)&&Vg(this,this.fa())}};
k.Oa=function(){var a=v(this.ya,this);this.g.b=a};
k.addEventListener=function(a,b){this.f.push({eventType:a,listener:b});this.b.addEventListener(a,b)};
k.fa=function(){if(!this.b)return null;var a=this.b.getApiInterface();Ha(a,"getVideoData");for(var b={apiInterface:a},c=0,d=a.length;c<d;c++){var e=a[c],f=e;if(0==f.search("get")||0==f.search("is")){f=e;var g=0;0==f.search("get")?g=3:0==f.search("is")&&(g=2);f=f.charAt(g).toLowerCase()+f.substr(g+1);try{var h=this.b[e]();b[f]=h}catch(l){}}}b.videoData=this.b.getVideoData();b.currentTimeLastUpdated_=y()/1E3;return b};
k.Xa=function(a){a={playerState:a,currentTime:this.b.getCurrentTime(),duration:this.b.getDuration(),videoData:this.b.getVideoData(),videoStartBytes:0,videoBytesTotal:this.b.getVideoBytesTotal(),videoLoadedFraction:this.b.getVideoLoadedFraction(),playbackQuality:this.b.getPlaybackQuality(),availableQualityLevels:this.b.getAvailableQualityLevels(),videoUrl:this.b.getVideoUrl(),playlist:this.b.getPlaylist(),playlistIndex:this.b.getPlaylistIndex(),currentTimeLastUpdated_:y()/1E3,playbackRate:this.b.getPlaybackRate(),
mediaReferenceTime:this.b.getMediaReferenceTime()};this.b.getProgressState&&(a.progressState=this.b.getProgressState());this.b.getStoryboardFormat&&(a.storyboardFormat=this.b.getStoryboardFormat());Vg(this,a)};
k.Va=function(a){Vg(this,{playbackQuality:a})};
k.Wa=function(a){Vg(this,{playbackRate:a})};
k.Ta=function(){for(var a=this.b.getOptions(),b={namespaces:a},c=0,d=a.length;c<d;c++){var e=a[c],f=this.b.getOptions(e);if(f){b[e]={options:f};for(var g=0,h=f.length;g<h;g++){var l=f[g],m=this.b.getOption(e,l);b[e][l]=m}}else S(Error("getOptions() returns ["+a.join(", ")+"], but getOption("+e+") returns null."))}this.sendMessage("apiInfoDelivery",b)};
k.Za=function(){Vg(this,{muted:this.b.isMuted(),volume:this.b.getVolume()})};
k.Ya=function(a){a={currentTime:a,videoBytesLoaded:this.b.getVideoBytesLoaded(),videoLoadedFraction:this.b.getVideoLoadedFraction(),currentTimeLastUpdated_:y()/1E3,playbackRate:this.b.getPlaybackRate(),mediaReferenceTime:this.b.getMediaReferenceTime()};this.b.getProgressState&&(a.progressState=this.b.getProgressState());Vg(this,a)};
k.dispose=function(){Wg.u.dispose.call(this);for(var a=0;a<this.f.length;a++){var b=this.f[a];this.b.removeEventListener(b.eventType,b.listener)}this.f=[]};function Xg(){J.call(this);this.b=new L;cc(this,x(dc,this.b))}
z(Xg,J);Xg.prototype.subscribe=function(a,b,c){return this.g?0:this.b.subscribe(a,b,c)};
Xg.prototype.D=function(a){return this.g?!1:this.b.D(a)};
Xg.prototype.j=function(a,b){this.g||this.b.K.apply(this.b,arguments)};function Yg(a,b,c){Xg.call(this);this.f=a;this.h=b;this.i=c}
z(Yg,Xg);function Mg(a,b,c){if(!a.g){var d=a.f;d.g||a.h!=d.b||(a={id:a.i,command:b},c&&(a.data=c),d.b.postMessage(nc(a),d.h))}}
Yg.prototype.l=function(){this.h=this.f=null;Yg.u.l.call(this)};function Zg(a,b,c){J.call(this);this.b=a;this.h=c;this.i=ye(window,"message",v(this.j,this));this.f=new Yg(this,a,b);cc(this,x(dc,this.f))}
z(Zg,J);Zg.prototype.j=function(a){var b;if(b=!this.g)if(b=a.origin==this.h)a:{b=this.b;do{b:{var c=a.source;do{if(c==b){c=!0;break b}if(c==c.parent)break;c=c.parent}while(null!=c);c=!1}if(c){b=!0;break a}b=b.opener}while(null!=b);b=!1}if(b&&(a=a.data,r(a))){try{a=JSON.parse(a)}catch(d){return}a.command&&(b=this.f,b.g||b.j("command",a.command,a.data))}};
Zg.prototype.l=function(){ze(this.i);this.b=null;Zg.u.l.call(this)};function $g(){var a=Na(window,"settings","experiments","flags","html5_serverside_pagead_id_sets_cookie")||Q("EXP_HTML5_SERVERSIDE_PAGEAD_ID_SETS_COOKIE",!1)||T("html5_serverside_pagead_id_sets_cookie")?"//googleads.g.doubleclick.net/pagead/id?exp=nomnom":"//googleads.g.doubleclick.net/pagead/id",b=Ta(ah);return new K(function(c,d){b.P=function(a){Rd(a)?c(a):d(new bh("Request failed, status="+a.status,"net.badstatus"))};
b.onError=function(){d(new bh("Unknown request error","net.unknown"))};
b.Z=function(){d(new bh("Request timed out","net.timeout"))};
Yd(a,b)})}
function bh(a,b){A.call(this,a+", errorCode="+b);this.errorCode=b;this.name="PromiseAjaxError"}
n(bh,A);function ch(a){this.f=void 0===a?null:a;this.g=0;this.b=null}
ch.prototype.then=function(a,b,c){return this.f?this.f.then(a,b,c):1===this.g&&a?(a=a.call(c,this.b),uc(a)?a:dh(a)):2===this.g&&b?(a=b.call(c,this.b),uc(a)?a:eh(a)):this};
ch.prototype.getValue=function(){return this.b};
tc(ch);function eh(a){var b=new ch;a=void 0===a?null:a;b.g=2;b.b=void 0===a?null:a;return b}
function dh(a){var b=new ch;a=void 0===a?null:a;b.g=1;b.b=void 0===a?null:a;return b}
;function fh(a){A.call(this,a.message||a.description||a.name);this.isMissing=a instanceof gh;this.isTimeout=a instanceof bh&&"net.timeout"==a.errorCode;this.isCanceled=a instanceof Cc}
n(fh,A);fh.prototype.name="BiscottiError";function gh(){A.call(this,"Biscotti ID is missing from server")}
n(gh,A);gh.prototype.name="BiscottiMissingError";var ah={format:"RAW",method:"GET",timeout:5E3,withCredentials:!0},hh=null;function ih(){if("1"===Na(Q("PLAYER_CONFIG",{}),"args","privembed"))return zc(Error("Biscotti ID is not available in private embed mode"));hh||(hh=Bc($g().then(jh),function(a){return kh(2,a)}));
return hh}
function jh(a){a=a.responseText;if(0!=a.lastIndexOf(")]}'",0))throw new gh;a=JSON.parse(a.substr(4));if(1<(a.type||1))throw new gh;a=a.id;lh(a);hh=dh(a);mh(18E5,2);return a}
function kh(a,b){var c=new fh(b);lh("");hh=eh(c);0<a&&mh(12E4,a-1);throw c;}
function mh(a,b){U(function(){Bc($g().then(jh,function(a){return kh(b,a)}),pa)},a)}
function lh(a){t("yt.ads.biscotti.lastId_",a,void 0)}
;function nh(){}
function oh(a){if("1"!==Na(Q("PLAYER_CONFIG",{}),"args","privembed")){a&&!u("yt.ads.biscotti.getId_")&&t("yt.ads.biscotti.getId_",ih,void 0);try{try{var b=u("yt.ads.biscotti.getId_");var c=b?b():ih()}catch(d){c=zc(d)}c.then(ph,nh);U(oh,18E5)}catch(d){S(d)}}}
var qh=0;
function ph(a){a:{try{var b=window.top.location.href}catch(Oa){b=2;break a}b=null!=b?b==window.document.location.href?0:1:2}b={dt:Fb,flash:gd||"0",frm:b};b.u_tz=-(new Date).getTimezoneOffset();var c=void 0===c?I:c;try{var d=c.history.length}catch(Oa){d=0}b.u_his=d;b.u_java=!!I.navigator&&"unknown"!==typeof I.navigator.javaEnabled&&!!I.navigator.javaEnabled&&I.navigator.javaEnabled();I.screen&&(b.u_h=I.screen.height,b.u_w=I.screen.width,b.u_ah=I.screen.availHeight,b.u_aw=I.screen.availWidth,b.u_cd=
I.screen.colorDepth);I.navigator&&I.navigator.plugins&&(b.u_nplug=I.navigator.plugins.length);I.navigator&&I.navigator.mimeTypes&&(b.u_nmime=I.navigator.mimeTypes.length);b.bid=a;b.ca_type=fd?"flash":"image";if(T("enable_server_side_search_pyv")||T("enable_server_side_mweb_search_pyv")){a=window;try{var e=a.screenX;var f=a.screenY}catch(Oa){}try{var g=a.outerWidth;var h=a.outerHeight}catch(Oa){}try{var l=a.innerWidth;var m=a.innerHeight}catch(Oa){}e=[a.screenLeft,a.screenTop,e,f,a.screen?a.screen.availWidth:
void 0,a.screen?a.screen.availTop:void 0,g,h,l,m];f=window.top;try{if(f.document&&!f.document.body)var w=new wb(-1,-1);else{var F=(f||window).document,qd="CSS1Compat"==F.compatMode?F.documentElement:F.body;w=(new wb(qd.clientWidth,qd.clientHeight)).round()}var wa=w}catch(Oa){wa=new wb(-12245933,-12245933)}w=0;p.SVGElement&&p.document.createElementNS&&(w|=1);wa={bc:w,bih:wa.height,biw:wa.width,brdim:e.join(),vis:{visible:1,hidden:2,prerender:3,preview:4,unloaded:5}[Db.webkitVisibilityState||Db.mozVisibilityState||
Db.visibilityState||""]||0,wgl:!!I.WebGLRenderingContext};for(var rd in wa)b[rd]=wa[rd]}b.bsq=qh++;de("//www.youtube.com/ad_data_204",{Ca:!1,B:b})}
;var Z=u("ytglobal.prefsUserPrefsPrefs_")||{};t("ytglobal.prefsUserPrefsPrefs_",Z,void 0);function rh(){this.b=Q("ALT_PREF_COOKIE_NAME","PREF");var a=Lb.get(""+this.b,void 0);if(a){a=decodeURIComponent(a).split("&");for(var b=0;b<a.length;b++){var c=a[b].split("="),d=c[0];(c=c[1])&&(Z[d]=c.toString())}}}
rh.prototype.get=function(a,b){sh(a);th(a);var c=void 0!==Z[a]?Z[a].toString():null;return null!=c?c:b?b:""};
rh.prototype.set=function(a,b){sh(a);th(a);if(null==b)throw Error("ExpectedNotNull");Z[a]=b.toString()};
rh.prototype.remove=function(a){sh(a);th(a);delete Z[a]};
rh.prototype.clear=function(){for(var a in Z)delete Z[a]};
function th(a){if(/^f([1-9][0-9]*)$/.test(a))throw Error("ExpectedRegexMatch: "+a);}
function sh(a){if(!/^\w+$/.test(a))throw Error("ExpectedRegexMismatch: "+a);}
function uh(a){a=void 0!==Z[a]?Z[a].toString():null;return null!=a&&/^[A-Fa-f0-9]+$/.test(a)?parseInt(a,16):null}
qa(rh);var vh=null,wh=null,xh=null,yh={};function zh(a){Re(a.payload_name,a.payload,Ue,void 0,void 0)}
function Ah(a){var b=a.id;a=a.ve_type;var c=De++;a=new Ce(void 0,a,c,void 0,void 0);yh[b]=a;b=af();c=$e();b&&c&&Se(b,c,a)}
function Bh(a){var b=a.csn;a=a.root_ve_type;if(b&&a&&(P("client-screen-nonce",b),P("ROOT_VE_TYPE",a),a=$e()))for(var c in yh){var d=yh[c];d&&Se(b,a,d)}}
function Ch(a){yh[a.id]=new Ce(a.tracking_params)}
function Dh(a){var b=af();a=yh[a.id];b&&a&&Te(Ue,{click:{csn:b,visualElement:Ee(a)}})}
function Eh(a){a=a.ids;var b=af();if(b)for(var c=0;c<a.length;c++){var d=yh[a[c]];if(d){var e=b,f=Ue;T("interaction_logging_on_gel_web")?Re("visualElementShown",{csn:e,ve:Ee(d),eventType:1},f):Te(f,{visibilityUpdate:{csn:e,visualElements:[Ee(d)]}},void 0)}}}
function Fh(){var a=vh;a&&a.startInteractionLogging&&a.startInteractionLogging()}
;t("yt.setConfig",P,void 0);t("yt.config.set",P,void 0);t("yt.setMsg",me,void 0);t("yt.msgs.set",me,void 0);t("yt.logging.errors.log",ke,void 0);
t("writeEmbed",function(){var a=Q("PLAYER_CONFIG",void 0);oh(!0);"gvn"==a.args.ps&&(document.body.style.backgroundColor="transparent");var b=document.referrer,c=Q("POST_MESSAGE_ORIGIN");window!=window.top&&b&&b!=document.URL&&(a.args.loaderUrl=b);Q("LIGHTWEIGHT_AUTOPLAY")&&(a.args.autoplay="1");a.args.autoplay&&Kg(a.args);vh=a=Eg(a);a.addEventListener("onScreenChanged",Bh);a.addEventListener("onLogClientVeCreated",Ah);a.addEventListener("onLogServerVeCreated",Ch);a.addEventListener("onLogToGel",zh);
a.addEventListener("onLogVeClicked",Dh);a.addEventListener("onLogVesShown",Eh);a.addEventListener("onReady",Fh);b=Q("POST_MESSAGE_ID","player");Q("ENABLE_JS_API")?xh=new Wg(a):Q("ENABLE_POST_API")&&r(b)&&r(c)&&(wh=new Zg(window.parent,b,c),xh=new Qg(a,wh.f));Q("BG_P")&&(Q("BG_I")||Q("BG_IU"))&&Ld();re()},void 0);
t("yt.www.watch.ads.restrictioncookie.spr",function(a){ge(a+"mac_204?action_fcts=1");return!0},void 0);
var Gh=kd(function(){$f("ol");var a=rh.getInstance(),b=!!((uh("f"+(Math.floor(119/31)+1))||0)&67108864),c=1<window.devicePixelRatio;if(document.body&&gc(document.body,"exp-invert-logo"))if(c&&!gc(document.body,"inverted-hdpi")){var d=document.body;d.classList?d.classList.add("inverted-hdpi"):gc(d,"inverted-hdpi")||(d.className+=0<d.className.length?" inverted-hdpi":"inverted-hdpi")}else!c&&gc(document.body,"inverted-hdpi")&&hc();if(b!=c){b="f"+(Math.floor(119/31)+1);d=uh(b)||0;d=c?d|67108864:d&-67108865;
0==d?delete Z[b]:Z[b]=d.toString(16).toString();a=a.b;c=[];for(var e in Z)c.push(e+"="+encodeURIComponent(String(Z[e])));bf(a,c.join("&"),63072E3)}}),Hh=kd(function(){var a=vh;
a&&a.sendAbandonmentPing&&a.sendAbandonmentPing();Q("PL_ATT")&&(Kd=null);a=0;for(var b=pe.length;a<b;a++)oe(pe[a]);pe.length=0;Id("//static.doubleclick.net/instream/ad_status.js");qe=!1;P("DCLKSTAT",0);ec(xh,wh);if(a=vh)a.removeEventListener("onScreenChanged",Bh),a.removeEventListener("onLogClientVeCreated",Ah),a.removeEventListener("onLogServerVeCreated",Ch),a.removeEventListener("onLogToGel",zh),a.removeEventListener("onLogVeClicked",Dh),a.removeEventListener("onLogVesShown",Eh),a.removeEventListener("onReady",
Fh),a.destroy();yh={}});
window.addEventListener?(window.addEventListener("load",Gh),window.addEventListener("unload",Hh)):window.attachEvent&&(window.attachEvent("onload",Gh),window.attachEvent("onunload",Hh));}).call(this);
