class User < ApplicationRecord
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable

         has_many :matches_users
         has_many :matches, :through => :matches_users

#<<<<<<< HEAD
         # crea un usuario en la base de datos con unos parametros que contengan:
         # NAME, EMAIL
         def self.create_with_params(params)
             User.create!(:email => params[:email], :password => params[:password])
         end
#=======
#>>>>>>> 9b268951e461a9e6c877f88f68c7588c492ff806

end
